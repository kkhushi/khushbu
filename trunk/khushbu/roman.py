#!/usr/bin/env python

def printit(k,ch):            #function to print characters repeatedly
   r = ''
   for i in range(0, k):
     r+=ch
   return r

def roman(x):                 #function to print roman equivalent 
   r = []
   k = x/1000  
   r.append(printit(k,'m'))   #m = 1000
   x = x%1000

   if x >= 900:               #cm = 900(1000-100) 
      r.append('cm')
      x-=900

   elif x >= 500:             #d = 500
      r.append('d')
      x -=500

   elif x >= 400:             #cd = 400(500-100)
      r.append('cd')
      x -=400

   k = x/100
   r.append(printit(k,'c'))   #c = 100
   x = x%100

   if x >=90:
      r.append('xc')          #xc = 90(100-10) 
      x-=90
   if x >= 50:
      r.append('l')           #l = 50
      x-=50
   elif x >= 40:
      r.append('xl')          #xl = 40(50 -10)   
      x -=40

   k = x/10
   r.append(printit(k,'x'))   #x = 10
   x = x%10

   if x ==4:
      r.append('iv')          #iv = 4(5-1)
      x = 0
   elif x == 9:
      r.append('ix')          #ix = 9(10-1) 
      x = 0
   elif x >=5:
      r.append('v'),          #v = 5
      x-=5;

   r.append(printit(x,'i'))   #i = 1
   n = ''.join(r)
   return n

x = int(raw_input("Enter a number:\t"))
print 'The Roman equivalent is\t',
n = roman(x)
print n + '\n'

#khushbu@khushbu-desktop:~$ ./roman.py
#Enter a number: 56
#The Roman equivalent is lvi 

#khushbu@khushbu-desktop:~$ ./roman.py
#Enter a number: 67
#The Roman equivalent is lxvii 

#khushbu@khushbu-desktop:~$ ./roman.py
#Enter a number: 999
#The Roman equivalent is cmxcix

#khushbu@khushbu-desktop:~$ ./roman.py
#Enter a number: 34
#The Roman equivalent is xxxiv

