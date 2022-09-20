
#	matrixMult4.py
#
# Author: David Galilei Natale
#
# January 2022
#
# I used Python 3.8.
#
# Enter the Python interpreter and type the following commands to run:
# >>> import matrixMult4
# >>> matrixMult4.matrixMult()
#
# The last entry in the PYMATRIXRESULT file is: 26552298924670988231000. 
#
# Program ran in 13 days.



def matrixMult():


	sum = 0

	A =[[0 for a in range(13967)] for b in range(13967)]

	for a in range(13963):
		for b in range(13964):
			sum = sum +10
			A[a][b] = sum


	sum = 0

	B = [[0 for c in range(13967)] for d in range(13967)]

	for c in range(13964):
		for d in range(13967):
			sum = sum + 10
			B[c][d] = sum

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


	R = [[0 for i in range(13967)] for j in range(13967)]
 
	# Iterate through rows of A.
	for i in range(len(A)):

		# Iterate through columns of B.
		for j in range(len(B[0])):

			# Iterate through rows of B.
			for k in range(len(B)):
				R[i][j] += A[i][k] * B[k][j]

	outFile3 = open('PYMATRIXRESULT','w')
	for r in R:
		outFile3.write(str(r))
	outFile3.close()

