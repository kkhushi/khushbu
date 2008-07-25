def power(s):
   n=2**s
   sum=0
   while n:
      sum
      sum+=n%10
      n=n/10
   return sum

>>> p=int(raw_input("enter the power:\t"))
enter the power:        7
>>> q=power(p)
>>> print " the required sum is:",q
 the required sum is: 11
