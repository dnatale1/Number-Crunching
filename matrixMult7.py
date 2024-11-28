
#	matrixMult7.py
#
# Author: David Galilei Natale
#
# November 2024
#
# I used PyTorch 2.4 and Python 3.9.
#
# The last entry in the PYMATRIXRESULT file is: 197718884467482273737867264. 
#
# Ran on Intel Max Series GPU 1100 in Intel's Tiber Developer Cloud for 2 hours.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

A =[[0 for a in range(83067)] for b in range(83067)]

for a in range(83063):
	for b in range(83064):
		sum = sum +10
		A[a][b] = sum

T = torch.tensor(A)

sum = 0

B = [[0 for c in range(83067)] for d in range(83067)]

for c in range(83064):
	for d in range(83067):
		sum = sum + 10
		B[c][d] = sum

U = torch.tensor(B)

print(len(A))

print(len(B[0]))

print(len(B))

outFile1 = open('PYMATRIX1', 'w')
for m in T:
	outFile1.write(str(m))
outFile1.close()


outFile2 = open('PYMATRIX2', 'w')
for n in U:
	outFile2.write(str(n))
outFile2.close()

T = T.to(torch.double)
U = U.to(torch.double)

V = torch.mm(T, U)

torch.set_printoptions(precision = 26)

outFile3 = open('PYMATRIXRESULT','w')
for r in V:
	outFile3.write(str(r))
outFile3.close()

t2 = datetime.datetime.now()

print (t2 - t1)


