#!/usr/bin/env python
def factorize(n):
   a = []
   for x in range(n,0,-1):
      if n%x == 0:
         a.append(x)
   return a

n = int(raw_input("Enter a number:\t"))
a = factorize(n)
print 'The factors of %d are' %(n),
print a

