#!/usr/bin/env python
import os.path

path = raw_input("Enter path for file:\t")
if os.path.exists(path):
   if os.path.islink(path):
      print 'It is a symbolic link'
   elif os.path.isdir(path):
      print 'Given path is a directory'
   elif os.path.isfile(path):
      print 'It is a file'
else:
   print "specified path doesn't exist"


