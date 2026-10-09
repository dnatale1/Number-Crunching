
#	matrixMultTwee.py
#
# Author: David Galilei Natale
#
# October 2026
#
# I used PyTorch 2.6 and Python 3.10.
#
# The last entry in the PYMATRIXRESULT3D file is: .
#                                                 
# Ran on Jarvislabs.ai GPU Cloud Platform in India for 2 minutes.

# My matrixMultThreeDimensions program where I was creating Python nested lists of 2037^3 or 8.5 billion elements, 
# introduced massive memory overhead. 
# A standard Python list of that size requires hundreds of gigabytes of RAM. 
# Converting it afterwards with torch.tensor() duplicates this memory requirement.
# MatrixMultThreeDimensionsGPU bypasses lists and loops entirely by generating tensors natively using PyTorch vectorization.
# Note: Because the values exceed 2.14 X 10^9, torch.int64 (LongTensor) is used to prevent integer overflow.



import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

# 1. Generate localized slices directly to save RAM
# Slices can be computed independently and kept to their true shapes
# instead of embedding them inside a giant (2537, 2537, 2537) zero matrix.

# For example, if you only want the product of the active subsets:
T_active = torch.arange(10, (2533 * 2534 * 2535) * 10 + 1, 10, dtype=torch.int64).view(2533, 2534, 2535)
U_active = torch.arange(10, (2535 * 2536 * 2537) * 10 + 1, 10, dtype=torch.int64).view(2535, 2536, 2537)

# To perform batch matrix multiplication, dimensions must match:
# T_active shape: (B, M, K) -> e.g., (2533, 2534, 2535)
# U_active shape: (B, K, N) -> The batch size 'B' must match! 
# Currently, T_active has 2533 batches, while U_active has 2535 batches.


# 1. Generate Tensor T

T = torch.arange(10, (2637 * 2637 * 2637) * 10 + 1, 10, dtype=torch.int64).view(2637, 2637, 2637)

sum = 0

# 2. Generate Tensor U

U = torch.arange(10, (2637 * 2637 * 2637) * 10 + 1, 10, dtype=torch.int64).view(2637, 2637, 2637)


outFile1 = open('PYMATRIX13D', 'w')
for m in T:
	outFile1.write(str(m))
outFile1.close()

HighestValueMatrix1 = T.max()

print ('Highest Value Matrix 1: ', HighestValueMatrix1)

outFile2 = open('PYMATRIX23D', 'w')
for n in U:
	outFile2.write(str(n))
outFile2.close()

HighestValueMatrix2 = U.max()

print ('Highest Value Matrix 2: ', HighestValueMatrix2)


T = T.to(torch.double)
U = U.to(torch.double)

V = torch.bmm(T, U)

torch.set_printoptions(precision = 25)

outFile3 = open('PYMATRIXRESULT3D','w')
for r in V:
	outFile3.write(str(r))
outFile3.close()

HighestValue = V.max()

print ('Highest Value: ', HighestValue)

t2 = datetime.datetime.now()

print (t2 - t1)


#Why are these adjustments necessary? 
#1)Time: The original for loops would take hours to run sequentially in Python. The vectorized code completes in seconds.
#2)Memory Management: Instead of heavy Python object wrappers, PyTorch allocates a raw block of contiguous memory.

#Something to ponder for the future:
#A single 2037X2037X2037 tensor using int64 requires 63GB of RAM. Running both T and U concurrently doubles this. 
#If memory is depleted, allocate these as sparse tensors, use memory-mapped storage, or process them in smaller chunks.
        
