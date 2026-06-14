
#	matrixMultThreeDimensions.py
#
# Author: David Galilei Natale
#
# June 2026
#
# I used PyTorch and Python 3.10.
#
# The last entry in the PYMATRIXRESULT3D file is: 14,427,899,183,446,228,832,616,448
#
# Ran on JarvisLabs GPU Cloud for 2 hours.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

A = [[[0 for a in range(2037)] for b in range(2037)] for c in range(2037)]

for a in range(2033):
	for b in range(2034):
		for c in range(2035):
			sum = sum + 10
			A[a][b][c] = sum

T = torch.tensor(A)

sum = 0

B = [[[0 for d in range(2037)] for e in range(2037)] for f in range(2037)]

for d in range(2035):
	for e in range(2036):
		for f in range(2037):
			sum = sum + 10
			B[d][e][f] = sum

U = torch.tensor(B)

print(len(A))

print(len(B[0]))

print(len(B))

outFile1 = open('PYMATRIX13D', 'w')
for m in T:
	outFile1.write(str(m))
outFile1.close()


outFile2 = open('PYMATRIX23D', 'w')
for n in U:
	outFile2.write(str(n))
outFile2.close()

T = T.to(torch.double)
U = U.to(torch.double)

V = torch.bmm(T, U)

torch.set_printoptions(precision = 25)

outFile3 = open('PYMATRIXRESULT3D','w')
for r in V:
	outFile3.write(str(r))
outFile3.close()

t2 = datetime.datetime.now()

print (t2 - t1)

