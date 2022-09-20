# twoToThePowerOfNImprovedEvenMore.py

# Author: David Galilei Natale
# Last edited: January 2019

# Enter the Python interpreter and type the following commands to run:
# >>> import twoToThePowerOfNImprovedEvenMore
# >>> twoToThePowerOfNImprovedEvenMore.pow(enter value)

# On my computer powered with an Intel 3.6 GHz CPU,
# 2^32,212,254,704 was calculated and printed in 118 hours.
# This number has 9,696,854,894 digits,
# starts with 7450370303 and ends with 7593942016.

# NOTE: This is the highest power of 2 that can be computed using
# the marshal module.  The reason is the maximum file size for the
# marshal.dump function is: 2^32 - 1 (4,294,967,295) bytes.

# I used Python 3.6.

import datetime
import math
import marshal

def pow(x):
	t1 = datetime.datetime.now()

	y = 2**x

	outFile = open('NthPower', 'wb')
	marshal.dump(y, outFile)
	outFile.close()

	outFile = open('NthPower', 'rb')
	b = marshal.load(outFile)

	print ('\n\n','2 ^', x,' has', math.trunc(math.log10(b)+1), 'digits.')

	print ('\n\nThe first 10 digits are: ', b // 10**(int(math.log(b,10)) - 10 + 1))

	print ('\n\nThe last 10 digits are: ', b//10**9%10,b//10**8%10,b//10**7%10,b//10**6%10,b//10**5%10,b//10**4%10,b//10**3%10,b//10**2%10, b//10**1%10,b//10**0%10)
		
	t2 = datetime.datetime.now()

	print (t2 - t1)





