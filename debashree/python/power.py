>>> def powersum(ps):
	pow = 2**ps
	sum = 0
	while pow>0:
		sum = sum+(pow%10)
		pow = pow/10
	return sum

>>> p = int(raw_input("Enter the power:\n"))
Enter the power:
5
>>> s = powersum(p)
>>> s
5
