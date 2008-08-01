def factors(n):
	f = []
	for i in range(n,0,-1):
		if n%i==0 :
			f.append(i)
	return f

>>> n = int(raw_input("Enter a number:\n"))
Enter a number:
24
>>> m = factors(n)
>>> print m
[24, 12, 8, 6, 4, 3, 2, 1]
