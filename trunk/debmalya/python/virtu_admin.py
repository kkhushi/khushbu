# /usr/bin/env python

import os

### Run this program as a root user.
### I've tried to access /proc fs and some more utils which needs root priviledge.
### There's also a method called os.uname but I didn't find that so flexible like the bash command.
### that's why I stuck with the basic bash sysadmin commands. using only os.system() to execute.
### better version can be made with extensive use of pipes, but, I'm only a novice. will upgrade it someday.
### + point is that, I now have a good command on these system utils and sysadmin commands now :)


print "Getting Kernel and Current Language Information...";
os.system("echo Operating System :> kernel.txt")
os.system("uname -o >> kernel.txt");
os.system("echo Kernel Version :>> kernel.txt");
os.system("uname -v >> kernel.txt");
os.system("set | egrep '(LANG)' >> kernel.txt");
os.system("echo kernel Release : >> kernel.txt")
os.system("uname -r >> kernel.txt");
os.system("echo Kernel Modules :  >> kernel.txt");
os.system("/sbin/lsmod  >> kernel.txt");

print "\nDetails can be found out in kernel.txt file\n";

print "\nNow tracking Memory usage ( in Kilobytes )...\n";
os.system("free -k > meminfo.txt");
os.system("vmstat >> meminfo.txt");
print "\nDetails can be found out in meminfo.txt file\n";

print "Now Looking up Filesystem and Storage Information :\n";
os.system("df -i > storage.txt");
print "Details can be found on storage.txt file.";

print "Now looking up, what processes are running...";
os.system("ps > process.txt");
print "Details can be found in process.txt file.";

print "Now looking up, How the CPU is behaving...";
os.system("top -n 1 > cpu_utiliz.txt");
print "Details can be found in cpu_utiliz.txt file.";

print "Now looking at SELinux Status.. :)";
os.system("/usr/sbin/sestatus > selinux_stat.txt");

print "What Runlevel is now : ";
os.system("echo Current Runlevel is : > runlevel.txt");
os.system("/sbin/runlevel >> runlevel.txt");
os.system("/sbin/chkconfig >> runlevel.txt");


print "\nNow we are upto access such Data that requires you to be Root..."
#a = os.system("su");
	
#if (a==0):
os.system("cat /var/log/messages > syslog.txt");

os.system("cp /var/log/rpmpkgs rpm_pkg_installed.txt");

os.system("cp /var/log/yum.log yum_repository.txt");

os.system("cp /proc/cpuinfo processor.txt");
os.system("/usr/sbin/dmidecode --type processor >> processor.txt");
#print "0";
os.system("/usr/sbin/dmidecode --type BIOS > bios.txt");
#print "1";
os.system("cp /proc/partitions partition_no.txt");

os.system(" /sbin/iptables -L | cat > firewall_stat.txt");
#print "2";
os.system("/usr/sbin/dmidecode --type system --type baseboard > form_factor_sys_baseboard.txt");
os.system("/usr/sbin/dmidecode --type chassis --type processor > form_factor_chasis_processor.txt");
os.system("/usr/sbin/dmidecode --type memory --type cache > form_factor_memory_cache.txt");
os.system("/usr/sbin/dmidecode --type connector --type slot > form_factor_connector_slot.txt");
#print "3";
#os.system("ls");
#	a=0;
##elif(a!=0):
#	print "You are not Authorised... Sorry mate..:)";


print "\nAuthor : ecntrk.k0mputer.g33k@gmail.com\n";

 
