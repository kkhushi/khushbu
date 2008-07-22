#!/usr/bin/env python
import pwd
name = raw_input("your  user name :")
print "\nThe user information : \n"

print pwd.getpwnam(name)

