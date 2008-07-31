#! usr/bin/env python
 

 
import urllib2

n = raw_input("enter the company")
l = "http://finance.yahoo.com/q?s="
s = l + n

 
link = urllib2.urlopen(s)
data = link.read()

sub = "Last Trade"
al = data.find(sub)

ala=al+52
aa=ala+6
print "The Last Trade is :"
print data[ala:aa]


