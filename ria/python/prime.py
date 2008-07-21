#!/usr/bin/env python
def prime():
    count = 0
    for n in range(2,1000000):
        for x in range(2, n):
            if n%x ==0 :
                break
        else:
            print n
            count = count + 1
    print "the total number is" count
    

