#!/usr/bin/env python
import os.path
n = raw_input("enter the name of the main file:")
data = ''
index = 0
if os.path.exists(n):
    while os.path.isfile(n + "." + str(index)):
        nread = open(n + "." + str(index), "r")
        data = data + nread.read()
        os.remove(n + "." + str(index))
        index = index + 1
        
    file = open("new" + n, "w")
    file.write(data)
else:
    print "no file exists"
