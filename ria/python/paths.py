#!/usr/bin/env python

import os.path
path = raw_input("enter the path:")

if os.path.isfile(path):
    print "file"
if os.path.isdir(path):
    print "directory"
if os.path.islink(path):
    print "link"
