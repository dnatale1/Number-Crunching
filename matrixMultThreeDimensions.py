
#	matrixMultThreeDimensions.py
#
# Author: David Galilei Natale
#
# December 2024
#
# I used PyTorch 2.4 and Python 3.9.
#
# The last entry in the PYMATRIXRESULT3D file is: 10,138,653,888,198,816,873,578,496. 
#
# Ran on Intel Max Series GPU 1100 in Intel's Tiber Developer Cloud for   2 hours.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

A = [[[0 for a in range(1937)] for b in range(1937)] for c in range(1937)]

for a in range(1933):
	for b in range(1934):
		for c in range(1935):
			sum = sum + 10
			A[a][b][c] = sum

T = torch.tensor(A)

sum = 0

B = [[[0 for d in range(1937)] for e in range(1937)] for f in range(1937)]

for d in range(1935):
	for e in range(1936):
		for f in range(1937):
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

