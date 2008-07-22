#!/usr/bin/env python

import os, math
data = ''
name = raw_input("Enter the filename or path you want to regain:\t")
if os.path.exists(name+'0'):
  for i in range(0,5):
    s = name +str(i)
    new = open(s,'r')
    data+=new.read()
    os.remove(s)
  f = open(name,'w')
  f.write(data)
else:
  print "file doesn't exist"


