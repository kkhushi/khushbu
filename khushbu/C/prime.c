#!/usr/bin/env python
def findprime(a, b):
   flag = 0
   count = 0
   for x in range(a+1,b-1):
      for y in range(x-1,2, -1):
         if x%y == 0:
            flag = 1
            break
      if flag == 0:
         count+=1
      flag = 0
   return count
a = int(raw_input("Enter start number:\t"))
b = int(raw_input("Enter last number:\t"))
x = findprime(a,b)
print 'The prime numbers between %d and %d are'%(a,b),
print x



