# factorial1.py

# Author: David Galilei Natale
# Last edited: May 2019

# Enter the Python interpreter and type the following commands to run:
# >>> import factorial1
# >>> factorial1.fact1(enter value)

# On my computer powered with an Intel 3.6 GHz CPU,
# 1,100,000,000! was calculated and printed in 16 days.
# This number has 9,467,808,029 digits,
# starts with 3164148161 and ends with 0000000000.

# I used Python 3.6.

import datetime
import math
import marshal

def fact1(x):
	t1 = datetime.datetime.now()

	y = math.factorial(x)

	outFile = open('NthFactorial', 'wb')
	marshal.dump(y, outFile)
	outFile.close()

	a = open('NthFactorial', 'rb')
	b = pickle.load(a)

	print ('\n\n', x ,'! has', math.trunc(math.log10(b)+1), 'digits.')

	print ('\n\nThe first 10 digits are: ', b // 10**(int(math.log(b,10)) - 10 + 1))

	print ('\n\nThe last 10 digits are: ', b//10**9%10,b//10**8%10,b//10**7%10,b//10**6%10,b//10**5%10,b//10**4%10,b//10**3%10,b//10**2%10, b//10**1%10,b//10**0%10)
		
	t2 = datetime.datetime.now()

	print (t2 - t1)




