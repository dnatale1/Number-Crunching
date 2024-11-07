
#	matrixMult7.py
#
# Author: David Galilei Natale
#
# November 2024
#
# I used PyTorch 2.4 and Python 3.9.
#
# The last entry in the PYMATRIXRESULT file is: 51074157035155840259063808. 
#
# Program ran on Intel GPU Max 1100 Series for 55 minutes.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

A =[[0 for a in range(63367)] for b in range(63367)]

for a in range(63363):
	for b in range(63364):
		sum = sum +10
		A[a][b] = sum

T = torch.tensor(A)

sum = 0

B = [[0 for c in range(63367)] for d in range(63367)]

for c in range(63364):
	for d in range(63367):
		sum = sum + 10
		B[c][d] = sum

U = torch.tensor(B)

print(len(A))

print(len(B[0]))

print(len(B))

outFile1 = open('PYMATRIX1', 'w')
for m in A:
	outFile1.write(str(m))
outFile1.close()


outFile2 = open('PYMATRIX2', 'w')
for n in B:
	outFile2.write(str(n))
outFile2.close()

T = T.to(torch.double)
U = U.to(torch.double)

V = torch.mm(T, U)

torch.set_printoptions(precision = 25)

outFile3 = open('PYMATRIXRESULT','w')
for r in R:
	outFile3.write(str(r))
outFile3.close()

t2 = dateetime.datetime.now()

print (t2 - t1)


