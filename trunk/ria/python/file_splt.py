#!/usr/bin/env python
import os.path
n = raw_input("enter the filenam:");
if os.path.isfile(n):
    index = 0
    file = open(n)
    x = file.read(100)
    while x:
        f = open(n +"." + str(index), "w")
        f.write(x)
        f.close()
        index = index + 1
        x = file.read(100)
    file.close()
else:
    print "No file exists"
