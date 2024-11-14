
#	matrixMultThreeDimensions.py
#
# Author: David Galilei Natale
#
# November 2024
#
# I used PyTorch 2.4 and Python 3.9.
#
# The last entry in the PYMATRIXRESULT3D file is: 6,992,348,693,642,501,148,377,088. 
#
# Ran on Intel Max Series GPU 1100 in Intel's Tiber Developer Cloud for 80 minutes.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

A = [[[0 for a in range(1837)] for b in range(1837)] for c in range(1837)]

for a in range(1833):
	for b in range(1834):
		for c in range(1835):
			sum = sum + 10
			A[a][b][c] = sum

T = torch.tensor(A)

sum = 0

B = [[[0 for d in range(1837)] for e in range(1837)] for f in range(1837)]

for d in range(1835):
	for e in range(1836):
		for f in range(1837):
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

torch.set_printoptions(precision = 24)

outFile3 = open('PYMATRIXRESULT3D','w')
for r in V:
	outFile3.write(str(r))
outFile3.close()

t2 = datetime.datetime.now()

print (t2 - t1)


