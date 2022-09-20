

#                            mersennePrime1.py
#
# AUTHOR: Bruce H. McCosar
#
# Posted on 5/21/07 at:
# http://bmccosar.wordpress.com/2007/05/21/mersenne-primes-5-omg/
#
# Enter the Python interpreter and type the following commands to run:
# >>> import mersennePrime1
# >>> mersennePrime1.mersenne(enter value)
#     where up thru (2^value)-1 is tested if value is odd
#           or thru (2^(value-1))-1 is tested if value is even
#
#                            NOTES: 
# 1. David Natale made a few minor modifications to this program.
# 2. You can stop and later restart the program where you left
#    off by changing the value of 'x' in the mersenne function.
# 3. This program runs faster using jython running on Linux.
# 4. I discovered the first 30 Mersenne primes over a period of 14 months
#    (see mersennePrimes.doc for the list).

import datetime

def is_prime(n):
	"""Determines if a positive number is prime or not."""
	top = int(n**0.5)
	factor = 1
	while factor < top:
		factor += 2
		if n % factor == 0:
			return False
	return True

def lucas_lehmer_test(prime, mersenne_prime):
	"""
	The actual Lucas-Lehmer test only works for odd exponents.
	http://en.wikipedia.org/wiki/Lucas-Lehmer_test_for_Mersenne_numbers
	"""
	
	s = 4	
	for x in xrange(prime-2):
		s = ((s*s) - 2) % mersenne_prime
	if s == 0:
		return True
	return False

def mersenne(limit):
    	"""
    	Returns a list of Mersenne Primes up to a given limit.
    	This new version uses the Lucas-Lehmer test:

    	http://en.wikipedia.org/wiki/Lucas-Lehmer_test_for_Mersenne_numbers

    	Because it only works for odd exponents, there is one Mersenne
        prime which would habitually be left off -- M(2) = 3.  
        Therefore, I'm starting with 3 as a given.  
    	"""

	t1 = datetime.datetime.now()
	cache = [3]
	y = 1
	print '\nMersenne Prime',y,'=',cache[y-1]
	for x in xrange(3,limit+1,2):
		if is_prime(x):
			print 'Prime X = ',x 
			candidate = (2**x) - 1
			if lucas_lehmer_test(x,candidate):
				cache.append(candidate)
				y += 1
				print '\nMersenne Prime',y,'=',cache[y-1]

	t2 = datetime.datetime.now()
	print '\n\nt1 = ',t1,' t2 = ',t2
	


