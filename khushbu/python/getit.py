#!/usr/bin/env python
import urllib2

def getprice(n):
  link = urllib2.urlopen( "http://finance.yahoo.com/q?s="+ n )
  data = link.read()
  x = data.find('Last Trade:')
  a = data[x+10 :x +70 ]
  x = a.find('<b>')
  b = a[x+2:x+9]
  return b

n = raw_input("Enter the company:\t")
b = getprice(n)
print b

#khushbu@khushbu-desktop:~$ ./getit.py
#Enter the company:      TCS.NS
#>793.85
#khushbu@khushbu-desktop:~$ ./getit.py
#Enter the company:      WIT
#>10.81<
#khushbu@khushbu-desktop:~$ ./getit.py
#Enter the company:      IBM
#>129.89


