#!/usr/bin/env python
import os.path
count = 0
n = raw_input("enter the filename");
if os.path.isfile(n):
    index = 0
    file = open(n)
    x = file.read(100)
    while x:
        f = open(n +"." + str(index), "w")
        f.write(x)
        count = count + 1
        f.close()
        index = index + 1
        x = file.read(100)
    file.close()
else:
    print "No file exists"

while index < count:
    f = open(n + "." + str(index))
    x = f.read()
    file = open(n, "w")
    file.write(x)
    f.close()
    index = index + 1
file.close()

