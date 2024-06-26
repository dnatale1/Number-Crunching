

# twoToThe1024Elevation.py

# Author: David Galilei Natale

# Last edited: April 2024

# I used Intel's Distribution for Python.


import datetime
import math


t1 = datetime.datetime.now()

b = (2 ** 1024) ** 33554432

c = math.trunc(math.log10(b) + 1)

print ('(2 ^ 1024) ^ 33554432 has ', c , ' digits')

print ('\n\nThe first 10 digits are: ', b // 10**(c - 10))

print ('\n\nThe last 10 digits are: ', b//10**9%10,b//10**8%10,b//10**7%10,b//10**6%10,b//10**5%10,b//10**4%10,b//10**3%10,b//10**2%10, b//10**1%10,b//10**0%10)

t2 = datetime.datetime.now()

print (t2 - t1)


# (2 ^ 1024) ^ 33554432 has  10343311892  digits


# The first 10 digits are:  8601383447


# The last 10 digits are:  1 3 5 4 2 3 3 8 5 6
# 5 days, 17:46:58.368553
