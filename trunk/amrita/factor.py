def factor(p):
   for i in range(p,0,-1):
     if p%i==0:
        print i
 
>>> a=int(raw_input("enter a number:"))
enter a number:45
>>> l=factor(a)
45
15
9
5
3
1

