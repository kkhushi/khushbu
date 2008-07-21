#!/usr/bin/env python

import urllib2
n = raw_input("enter the company")    
l = "http://finance.yahoo.com/q?s="
s = l + n
req = urllib2.Request(url = s,data = 'Last trade:')

link = urllib2.urlopen(s)
data = link.read()
x = data.find('Last Trade:')

data =  data[x + 52:x + 72]
print data[: data.find("</b>")]
