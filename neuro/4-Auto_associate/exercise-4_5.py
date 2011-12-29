#!/usr/bin/python

from numpy import *

def vector_compare(x1, x2, size):
	for i in range(size):
		if( x1.item(i) != x2.item(i) ):
			return 1
	return 0
		

print "Exercise 1 from part 4"

x1 = matrix('-1 1 -1 -1 1 -1 -1 -1')
x2 = matrix('-1 -1 1 -1 -1 -1 1 -1')

print "x1 = ", x1, "\n"
print "x2 = ", x2, "\n"

W = x1.getT() * x1 + x2.getT() * x2
W = W - eye(W.shape[0])

print "Weigh matrix W = \n", W, "\n"

# check for stability 5.b
res1 = sign(x1 * W)
if vector_compare(res1, x1, res1.shape[1]) == 0:
	print "Stable with x1, res = ", res1, "\n"
else:
	print "NOT Stable with x1, res = ", res1, "\n"

res2 = sign(x2 * W)
if vector_compare(res2, x2, res2.shape[1]) == 0:
	print "Stable with x2, res = ", res2, "\n"
else:
	print "NOT Stable with x2, res = ", res2, "\n"

# check for stability 5.c
xx = matrix('-1 1 -1 -1 1 -1 -1 1')
xy = matrix('-1 1 1 -1 1 -1 -1 -1')

res3 = sign(xx * W)
if vector_compare(res3, xx, res3.shape[1]) == 0:
	print "Stable with xx, res = ", res3, "\n"
else:
	print "NOT Stable with xy, res = ", res3, "\n"

res4 = sign(xy * W)
if vector_compare(res3, xy, res4.shape[1]) == 0:
	print "Stable with xy, res = ", res4, "\n"
else:
	print "NOT Stable with xy, res = ", res4, "\n"
