#!/usr/bin/env python
n = int(raw_input('enter the power:'))
a = pow(2,n)
print a
sum = 0
while a > 0:
    b = a%10
    sum = sum + b
    a = a/10
print sum
