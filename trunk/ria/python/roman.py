#!/usr/bin/env python

a = []
s = []
count = 0
n = int(raw_input("Enter the decimal number:"))
if n < 3999:
    while n > 0:
        x = n%10
        a.append(x)
        count = count + 1
        n = n/10
    
    if count>0:
        cha2 = 'I'
    
        if a[0] == 4:
            char1 = 'IV'
        elif a[0]>=5 and a[0]<=8:
            cha1 = 'V'
            char1 = cha1 + cha2*(a[0]-5)
        elif a[0] == 9:
            char1 = 'IX'
        else:
            char1 = cha2*a[0]
        s.append(char1)

    if count>1:
        cha2 = 'X'
    
        if a[1] == 4:
            char1 = 'XL'
        elif a[1]>=5 and a[1]<=8:
            cha1 = 'L'
            char1 = cha1 + cha2*(a[1]-5)
        elif a[1] == 9:
            char1 = 'XC' 
        else:
            char1 = cha2*a[1]
        s.append(char1)

    if count>2:
        cha2 = 'C'
    
        if a[2] == 4:
            char1 = 'CD'
        elif a[2]>=5 and a[2]<=8:
            cha1 = 'D'
            char1 = cha1 + cha2*(a[2]-5)
        elif a[2] == 9:
            char1 = 'CM'
        else:
            char1 = cha2*a[2]
        s.append(char1)

    if count>3:
        cha2 = 'M'
    
        char1 = cha2*a[3]
        s.append(char1)


    s.reverse()
    s = "".join(s)
    print s

else:
    print("invalid number")

