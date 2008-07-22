#!/usr/bin/env python
def findprime(a, b):
   flag = 0
   count = 0
   for x in range(a+1,b):
      for y in range(x/2,1, -1):
         if x%y == 0:
            flag = 1
            break
      if flag == 0:
         count+=1
      flag = 0
   return count

a = int(raw_input("Enter start number:\t"))
b = int(raw_input("Enter last number:\t"))
print 'There are %d prime numbers between %d and %d.\n'%(findprime(a,b),a,b)
