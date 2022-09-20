

# fibonacci4.py
#
# Author: Josiah Carlson
#
# Posted at ActiveState Programmer Network on 9/6/04
#
# This version runs slightly faster than my fibonacci3.py program.
#
# Enter the Python interpreter and type the following commands to run:
# >>> import fibonacci4
# >>> fibonacci4.fib4(enter value)
#
# On my computer powered with an Intel 3.6 GHz CPU,
# the 17,000,000th Fibonacci number is calculated  
# and printed in 174 seconds.
#
# I used Python 3.5.
#
# David Natale computed the 2,000,000,000th Fibonacci number. This number has
 417,975,281 digits, starts with 1414075068 and ends with 4439453125.


import datetime
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
	outFile = open('fiboAnswer','w')
	outFile.write(str(j))
	outFile.close()

	t2 = datetime.datetime.now()
	print (t2 - t1)
	



