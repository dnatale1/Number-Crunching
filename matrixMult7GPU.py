
#	matrixMult7GPU.py
#
# Author: David Galilei Natale
#
# November 2026
#
# I used PyTorch 2.6 and Python 3.10.
#
# The last entry in the PYMATRIXRESULT file is: 690,351,371,949,159,306,357,637,120. 
#
# Ran on Jarvislabs.ai GPU Cloud Platform in India for 10 minutes.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

# 1. Generate Tensor T
T = torch.zeros((106667, 106667), dtype=torch.int64)
elements_A = 106663 * 106664

# Create a flattened sequence [10, 20, 30, ...] and reshape it to fit the slice
seq_A = torch.arange(10, elements_A * 10 + 1, 10, dtype=torch.int64).view(106663, 106664)
T[:106663, :106664] = seq_A


sum = 0

# 2. Generate Tensor U
U = torch.zeros((106667, 106667), dtype=torch.int64)
elements_B = 106664 * 106667

# Create the sequence for B and reshape it to fit the slice
seq_B = torch.arange(10, elements_B * 10 + 1, 10, dtype=torch.int64).view(106664, 106667)
U[:106664, :106667] = seq_B


outFile1 = open('PYMATRIX1', 'w')
for m in T:
	outFile1.write(str(m))
outFile1.close()

HighestValueMatrix1 = T.max()

print ('Highest Value Matrix 1: ', HighestValueMatrix1)

outFile2 = open('PYMATRIX2', 'w')
for n in U:
	outFile2.write(str(n))
outFile2.close()

HighestValueMatrix2 = U.max()

print ('Highest Value Matrix 2: ', HighestValueMatrix2)

T = T.to(torch.double)
U = U.to(torch.double)

V = torch.mm(T, U)

torch.set_printoptions(precision = 26)

outFile3 = open('PYMATRIXRESULT','w')
for r in V:
	outFile3.write(str(r))
outFile3.close()

HighestValue = V.max()

print ('Highest Value: ', HighestValue)

t2 = datetime.datetime.now()

print (t2 - t1)


