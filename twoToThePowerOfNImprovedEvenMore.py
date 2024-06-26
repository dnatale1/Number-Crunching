
# twoToThePowerOfNImprovedEvenMore.py

# Author: David Galilei Natale
# Last edited: May 2024

# 2^50,000,000,000 has 15,051,499,784 digits,
# starts with 1581465640 and ends with 1787109376.

# I used Python 3.9.

# Program ran for 10 days on the Pitzer cluster at the Ohio Supercomputer Center.

import datetime
import math



t1 = datetime.datetime.now()

b = 2**50000000000

c = math.trunc(math.log10(b) + 1)

print ('2 ^ 50,000,000,000 has ', c , ' digits')

print ('\n\nThe first 10 digits are: ', b // 10**(c - 10))

print ('\n\nThe last 10 digits are: ', b//10**9%10,b//10**8%10,b//10**7%10,b//10**6%10,b//10**5%10,b//10**4%10,b//10**3%10,b//10**2%10, b//10**1%10,b//10**0%10)
		
t2 = datetime.datetime.now()

print (t2 - t1)






