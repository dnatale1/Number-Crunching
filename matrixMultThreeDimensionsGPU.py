
#	matrixMultThreeDimensionsGPU.py
#
# Author: David Galilei Natale
#
# September 2026
#
# I used PyTorch 2.6 and Python 3.10.
#
# The last entry in the PYMATRIXRESULT3D file is: 14,427,899,183,446,228,832,616,448
#
# Ran on JarvisLabs GPU Cloud in India for 2 hours.


import torch
import datetime

t1 = datetime.datetime.now()

sum = 0

# 1. Generate Tensor T
T = torch.zeros((2137, 2137, 2137), dtype=torch.int64)
elements_A = 2133 * 2134 * 2135

# Create a flattened sequence [10, 20, 30, ...] and reshape it to fit the slice
seq_A = torch.arange(10, elements_A * 10 + 1, 10, dtype=torch.int64).view(2133, 2134, 2135)
T[:2133, :2134, :2135] = seq_A


sum = 0

# 2. Generate Tensor U
U = torch.zeros((2137, 2137, 2137), dtype=torch.int64)
elements_B = 2135 * 2136 * 2137

# Create the sequence for B and reshape it to fit the slice
seq_B = torch.arange(10, elements_B * 10 + 1, 10, dtype=torch.int64).view(2135, 2136, 2137)
U[:2135, :2136, :2137] = seq_B


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

#Creating Python nested lists of this scale (2037^3 or approximately 8.46 billion elements) introduces massive memory overhead. A standard Python list of that size requires hundreds of gigabytes of RAM. Converting it afterwards with torch.tensor() duplicates this memory requirement.To run this instantly and efficiently, you should bypass Python lists and loops entirely and generate the tensors natively using PyTorch vectorization.
#Natively Optimized PyTorch Code: Because the values exceed 2.14 X 10^9, you must use torch.int64 (LongTensor) to prevent integer overflow.

# 1. Generate Tensor T
#T = torch.zeros((2037, 2037, 2037), dtype=torch.int64)
#elements_A = 2033 * 2034 * 2035

# Create a flattened sequence [10, 20, 30, ...] and reshape it to fit the slice
#seq_A = torch.arange(10, elements_A * 10 + 1, 10, dtype=torch.int64).view(2033, 2034, 2035)
#T[:2033, :2034, :2035] = seq_A

# 2. Generate Tensor U
#U = torch.zeros((2037, 2037, 2037), dtype=torch.int64)
#elements_B = 2035 * 2036 * 2037

# Create the sequence for B and reshape it to fit the slice
#seq_B = torch.arange(10, elements_B * 10 + 1, 10, dtype=torch.int64).view(2035, 2036, 2037)
#U[:2035, :2036, :2037] = seq_B

#Why This Fix Is Necessary? 1)Execution Time: The original for loops would take hours to run sequentially in Python. The vectorized code completes in a few milliseconds.
#2)Memory Management: Instead of heavy Python object wrappers, PyTorch allocates a raw block of contiguous memory.

#Hardware Warning: A single 2037 X 2037 X 2037 tensor using int64 requires ~63.1 GB of RAM. Running both T and U concurrently requires ~126.2 GB of RAM. If you are running out of system memory even with the optimized code, let me know. I can show you how to allocate these as sparse tensors, use memory-mapped storage, or process them in smaller chunks depending on your end goal.        

