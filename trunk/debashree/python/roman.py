>>> romannum = (('M',1000),('CM',900),('D',500),('CD',400),('C',100),('XC',90),
...    ('L',50),('XL',40),('X',10),('IX',9),('V',5),('IV',4),('I',1))
>>> def toRoman(n):
...    result = ""
...    if n<1 or n>4000:
...     return  None
...    for numeral,integer in romannum:
...     while n>=integer:
...       result += numeral
...       n-=integer
...    return result
... 
>>> n = int(raw_input("Enter the decimal number:\n"))
Enter the decimal number:
56
>>> toRoman(n)
'LVI'
>>> n = int(raw_input("Enter the decimal number:\n"))
Enter the decimal number:
-1
>>> toRoman(n)
>>> toRoman(46)
'XLVI'
>>> toRoman(14)
'XIV'
>>> 

