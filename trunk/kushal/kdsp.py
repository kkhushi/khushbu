#!/usr/bin/env python

import os.path

name = raw_input("Please enter the filename to split: ")
if os.path.isfile(name):
    index = 0
    fmain = open(name)
    x = fmain.read(100)
    while x:
        f = open(name+ "." + str(index), "w")
        f.write(x)
        f.close()
        index += 1
        x = fmain.read(100)
    fmain.close()
else:
    print "Sorry , but no such file exists"
