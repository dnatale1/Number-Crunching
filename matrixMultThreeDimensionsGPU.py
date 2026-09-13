
#	matrixMultThreeDimensionsGPU.py
#
# Author: David Galilei Natale
#
# September 2026
#
# I used PyTorch 2.6 and Python 3.10.
#
# The last entry in the PYMATRIXRESULT3D file is: 27,826,344,282,485,810,000,000,000.
#
# Ran on JarvisLabs GPU Cloud in India for 2 minutes.

# My matrixMultThreeDimensions program where I was creating Python nested lists of 2037^3 or 8.5 billion elements, introduced massive memory overhead. 
# A standard Python list of that size requires hundreds of gigabytes of RAM. 
# Converting it afterwards with torch.tensor() duplicates this memory requirement.
# MatrixMultThreeDimensionsGPU bypasses Python lists and loops entirely by generating the tensors natively using PyTorch vectorization.
# Note: Because the values exceed 2.14 X 10^9, torch.int64 (LongTensor) is used to prevent integer overflow.



import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

# 1. Generate Tensor T
T = torch.zeros((2237, 2237, 2237), dtype=torch.int64)
elements_A = 2233 * 2234 * 2235

# Create a flattened sequence [10, 20, 30, ...] and reshape it to fit the slice
seq_A = torch.arange(10, elements_A * 10 + 1, 10, dtype=torch.int64).view(2233, 2234, 2235)
T[:2233, :2234, :2235] = seq_A


sum = 0

# 2. Generate Tensor U
U = torch.zeros((2237, 2237, 2237), dtype=torch.int64)
elements_B = 2235 * 2236 * 2237

# Create the sequence for B and reshape it to fit the slice
seq_B = torch.arange(10, elements_B * 10 + 1, 10, dtype=torch.int64).view(2235, 2236, 2237)
U[:2235, :2236, :2237] = seq_B


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

HighestValue = V.max()

print ('Highest Value: ', HighestValue.item())

t2 = datetime.datetime.now()

print (t2 - t1)


#Why are these adjustments Necessary? 
#1)Execution Time: The original for loops would take hours to run sequentially in Python. The vectorized code completes in a few milliseconds.
#2)Memory Management: Instead of heavy Python object wrappers, PyTorch allocates a raw block of contiguous memory.

#Something to ponder for the future:
#A single 2037X2037X2037 tensor using int64 requires 63GB of RAM. Running both T and U concurrently doubles this. 
#If you are running out of system memory, allocate these as sparse tensors, use memory-mapped storage, or process them in smaller chunks.
        

