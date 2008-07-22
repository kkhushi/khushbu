#!/usr/bin/env python
def binary(n):
   a = []
   while(n):
      a.append(n%2)
      n/=2
   b=''
   while(a):
      b+=str(a.pop())
   return b
a = int(raw_input("Enter a number:\t"))
b = binary(a)
print 'The binary equivalent of %d is' %(a),
print b

khushbu@khushbu-desktop:~$ ./power.py
Enter a number: 4
The binary equivalent of 4 is 100
khushbu@khushbu-desktop:~$ ./power.py
Enter a number: 23
The binary equivalent of 23 is 10111
khushbu@khushbu-desktop:~$ ./power.py
Enter a number: 16
The binary equivalent of 16 is 10000


 
