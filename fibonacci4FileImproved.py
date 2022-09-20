

# fibonacci4FileImproved.py
#
# Author: Josiah Carlson
#
# Algorithm posted at ActiveState Programmer Network on 9/6/04.
#
# This version prints numbers to a file much faster than my fibonacci4.py program.
#
# Enter the Python interpreter and type the following commands to run:
# >>> import fibonacci4FileImproved
# >>> fibonacci4FileImproved.fib4(enter value)
#
# On my computer powered with an Intel 3.6 GHz CPU,
# the 110,000,000th Fibonacci number is calculated  
# and printed in 174 seconds.
#
# I used Python 3.6.
#
# David Galilei Natale computed the 40,000,000,000th Fibonacci number in September 2019. 
# This number has 8,359,505,610 digits, starts with 4463384990 and ends with 9560546875.


import datetime
import marshal
import math

def fib4(n):
	t1 = datetime.datetime.now()

	if 2 >= n:
		return 1
	t = 1
	while n >= t:
        	t *= 2
	t = int(t/4)
	i, j, k = 1, 1, 0
	while t > 0:
		B = j*j
		j *= i+k
		i = i*i + B
		k = k*k + B
		if n&t:
			k = j
			j = i
			i = j+k
		t = int(t/2)

	outFile = open('NthFibNum', 'wb')
	marshal.dump(j, outFile)
	outFile.close()

	x = open('NthFibNum', 'rb')
	y = marshal.load(x)

	print ('\n\nThe', n,'th Fibonacci number has', math.trunc(math.log10(y)+1), 'digits.')

	print ('\n\nThe first 10 digits are: ', y // 10**(int(math.log(y,10)) - 10 + 1))

	print ('\n\nThe last 10 digits are: ', y//10**9%10,y//10**8%10,y//10**7%10,y//10**6%10,y//10**5%10,y//10**4%10,y//10**3%10,y//10**2%10,y//10**1%10,y//10**0%10)
	
	t2 = datetime.datetime.now()
	print ('\n\n')
	print (t2 - t1)

