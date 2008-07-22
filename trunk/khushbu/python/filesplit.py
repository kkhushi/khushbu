#!/usr/bin/env python

import os, math

name = raw_input("Enter the filename or path:\t")
if os.path.exists(name):
  f = open(name, 'r')
  data = f.read()
  fsize = len(data)
  csize = fsize/5 +1
  f.seek(0)
  for i in range(0,5):
    s = name +str(i)
    new  = open(s,'w')
    new.write(f.read(csize))
    print s 
  os.remove(name)
else:
  print "file doesn't exist"


