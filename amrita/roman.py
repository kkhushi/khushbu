> PROGRAM:


def toroman(s):
      x=[]
      a=[]
      c=0
      while s>0:
         n=s%10
         x.append(n)
         c=c+1
         s/=10
      if c>0:
        d1 = 'I'
        d2 = 'V'
        if x[0] < 4:
          c1=d1*x[0]
        elif x[0] == 4:
          c1= 'IV'
        elif x[0]>=5 and x[0]<=8:
          c1 = d2 + d1*(x[0]-5)
        else:
          c1 = 'IX'
        a.append(c1)
      if c>1:
         d1 = 'X'
         d2 = 'L'
         if x[1] <4:
           c1 = d1*x[1]
         elif x[1] == 4:
           c1 = 'XL'
         elif x[1]>=5 and x[1]<=8:
           c1 = d2 + d1*(x[1]-5)
         else:
           c1 = 'XC'
         a.append(c1)
      if c>2:
         d1 = 'C'
         d2 = 'D'
         if x[2]< 4:
           c1 = d1*x[2]
         elif x[2] == 4:
           c1 = 'CD'
         elif x[2]>=5 and x[2]<=8:
           c1 = d2 + d1*(x[2]-5)
         else:
           c1 = 'CM'
         a.append(c1)
      if c>3:
         d1 = 'M'
         c1 = d1*x[3]
         a.append(c1)
      a.reverse()
      a="".join(a)
      print a 
t=int(raw_input("enter the number:"))
r= toroman(t)

> OUTPUT:
   
>>> t=int(raw_input("enter the number:"))
enter the number:13
>>> r= toroman(t)
XIII
>>> t=int(raw_input("enter the number:"))
enter the number:29
>>> r= toroman(t)
XXIX
   
 


