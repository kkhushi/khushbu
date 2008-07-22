#!/usr/bin/env python
def rev(a):
  a = [x for x in a ]
  a.reverse()
  b="".join(a)
  return b

d = raw_input("Enter a string")
c = rev(d)
print c


