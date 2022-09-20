
# fibonacci2.py

# Author: David Galilei Natale
# Last edited: February 2015

# Enter the Python interpreter and type the following commands to run:
# >>> import fibonacci2
# >>> fibonacci2.fib2(enter value)

# On my computer powered with an Intel 3.6 GHz CPU,
# the 4,150,000th Fibonacci number is calculated with 
# 100% accuracy and printed in 174 seconds.

# I used Python 3.2.3.

import datetime
def fib2(n):
	t1 = datetime.datetime.now()
	a,b,c = 0,1,1
	while c < n:
    		a,b=b,a+b
    		c += 1	
		
	outFile = open('fibonacciAnswer','w')
	outFile.write(str(b))
	outFile.close()
	t2 = datetime.datetime.now()
	print 't1 = ',t1,'  t2 = ',t2




