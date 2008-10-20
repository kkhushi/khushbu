#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright (C) 2008 Matteo Castellini <self {at} mcastellini [dot] net>,
# 
# Enhancement by Khushbu Mohta <khushi.pk@gmail.com> and
# Prakhar Agarwal <prakhar@fedoraproject.org>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


import dbus
from dbus.mainloop.glib import DBusGMainLoop
import gobject
from optparse import OptionParser
import os
import sys
import threading

# Here happens the actual installation process relying on live-iso-to-disk
class install_image(threading.Thread):
	def __init__(self, device):
		threading.Thread.__init__(self)
		self.device = device

	def run(self):
		if not option.dummy:
			device_name = self.device.GetProperty('block.device')+ '1'
			exit_status = os.system('./livecd-iso-to-disk --noverify %s %s' % (args[0], device_name))
        	if exit_status == 256 and option.erase:
		# Error 1: Not a valid filesystem (vfat or ext[23]).
		# Force creating a vfat filesystem on the partition (only in erase
		# mode, to avoid data loss)
			print 'Caught error 1'
			os.system('/sbin/mkdosfs -I -n usbdisk %s' % device_name)
			exit_status = os.system('./livecd-iso-to-disk --noverify %s %s' % (args[0], device_name))
		elif exit_status == 512:
		# Error 2: Partition needs a filesystem label.
		# Create a label according to the filesystem type
			print 'Caught error 2'
			if self.device.GetProperty('volume.fstype') == 'vfat':
				os.system('/sbin/dosfslabel %s usbdisk' % device_name)
			elif self.device.GetProperty('volume.fstype')[:3] == 'ext':
				os.system('/sbin/e2label %s usbdisk' % device_name)
			exit_status = os.system('./livecd-iso-to-disk --noverify %s %s' % (args[0], device_name))
		elif exit_status == 768:
		# Error 3: Partition isn't marked bootable.
		# Mark the partition as bootable
			print 'Caught error 3'
			os.system('sfdisk -A%s %s' % (device_name[-1], device_name[:-1]))
			exit_status = os.system('./livecd-iso-to-disk --noverify %s %s' % (args[0], device_name))
		elif exit_status == 1024:
		# Error 4: MBR appears to be blank
		# Rerun l-i-t-d with --reset-mbr option
			print 'Caught error 4'
			exit_status = os.system('./livecd-iso-to-disk --noverify --reset-mbr %s %s' % (args[0], device_name))
		elif exit_status == 1280 and option.erase:
		# Error 5: Generic error.
		# Completely erase and create one big partition on the device. This
		# should be used on in TFU cases since it is destructive, 
		# erase flage is here to point this out.
			print 'Caught error 5'
			parent_obj = bus.get_object('org.freedesktop.Hal', self.device.GetProperty('info.parent'))
			device_name = (dbus.Interface(parent_obj, 'org.freedesktop.Hal.Device')).GetProperty('block.device')
			os.system('/sbin/sfdisk %s << EOF\n,,6,*\n;\nEOF' % device_name)
			os.system('/sbin/mkdosfs -I -n usbdisk %s' % device_name + '1')
			exit_status = os.system('./livecd-iso-to-disk --noverify %s %s' % (args[0], device_name + '1'))
		elif exit_status == 0:
		# If everything is ok play some wonderful music
			os.system('/usr/bin/ogg123 -q "%s"' % option.sound)

# Tries to guess if the new device signaled by HAL is something we can work on
def check_device(udi):
	device_obj = bus.get_object('org.freedesktop.Hal', udi)
	device = dbus.Interface(device_obj, 'org.freedesktop.Hal.Device')
	try:
		category = device.GetProperty('info.category')
	except:
		return
	if category == 'storage':
	# Lock the device if it is usb, hotpluggable and removable, preventing
	# unwanted automounting procedures 
		if (device.GetProperty('storage.bus') == 'usb' and
		    device.GetProperty('storage.hotpluggable') and
		    device.GetProperty('storage.removable')):
			#device.AcquireInterfaceLock('org.freedesktop.Hal.Device.Storage', True)
			#device.Lock('KoboldLock')
			return device
			#device.Unlock()
			#device.ReleaseInterfaceLock
	elif category == 'volume':
	# Check if the parent device was locked by kobold, start the writing
	# process and after that unlock the device
		parent_obj = bus.get_object('org.freedesktop.Hal', device.GetProperty('info.parent'))
		parent = dbus.Interface(parent_obj, 'org.freedesktop.Hal.Device')
		if (parent.PropertyExists('info.locked') and
		    parent.GetProperty('info.locked') and 
		    not parent.IsLockedByOthers('org.freedesktop.Hal.Device.Storage') and
		    parent.GetProperty('info.locked.reason') == 'KoboldLock'):
			return device
			#parent.Unlock()
			#parent.ReleaseInterfaceLock('org.freedesktop.Hal.Device.Storage')

if __name__ == '__main__':
	if os.getuid() != 0:
		sys.stderr.write('You need to be root to run this script\n')
		sys.exit(1)

	# Command line parsing stuff, should be quite straightforward
	parser = OptionParser(usage='%prog [options] ISOFILE', version='%prog 0.1')
	parser.add_option('-a', '--ambush', action='store_true', dest='ambush',
		help='copy FILE on USB stick without giving a warning')
	parser.add_option('-d', '--dummy', action='store_true', dest='dummy',
		help='do not actually write FILE on USB stick')
	parser.add_option('-e', '--erase', action='store_true', dest='erase',
		help='erase the whole stick when unhandled errors happen')
	parser.add_option('-p', '--play', action='store', dest='sound',
		help='play SOUND after a successful creation', metavar='SOUND')
	parser.set_defaults(ambush=False, dummy=False, erase=False, sound='')
	(option, args) = parser.parse_args()

	if not args or not os.path.isfile(args[0]):
		print 'You must provide a valid ISOFILE file to be written'
		sys.exit(1)
	elif option.sound and not os.path.isfile(option.sound):
		print 'You must provide a valid SOUND file to be played'
		sys.exit(1)

	# Let's start D-Bus+HAL black magic!
	DBusGMainLoop(set_as_default=True)
	bus = dbus.SystemBus()
	hal_manager = bus.get_object('org.freedesktop.Hal', '/org/freedesktop/Hal/Manager')
	hal = dbus.Interface(hal_manager, 'org.freedesktop.Hal.Manager')
	devices = hal.GetAllDevices()
	devicelist = []
    
	for udi in devices:
		test = check_device(udi)
		if test:
			devicelist.append(test)
		#All USB sticks added to the list.
	thread = []
	while(len(devicelist)):
		dev = devicelist.pop()
		device_name = dev.GetProperty('block.device')+ '1'
	lock = True
        while lock and not option.ambush:
		lock = raw_input('Do you really want to copy the image file %s on %s?' % (args[0], device_name))
		# Creating Thread for each USB stick 
		if lock in ('y', 'ye', 'yes'):
			lock = False
			thread.append(install_image(dev))  
		elif lock in ('n', 'no', 'not'):
			continue

	t = len(thread)
	i = 0
	while(t):
		# Starting threads
		thread[i].start()
		i += 1
		t -= 1
    
	t = len(thread)
	i = 0
	while(t):
		# All the threads will be executed
		thread[i].join()
		i += 1
		t -= 1
    #loop = gobject.MainLoop()
    #loop.run()
