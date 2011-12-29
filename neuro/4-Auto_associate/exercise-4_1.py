#!/usr/bin/python

from numpy import *

print "Exercise 1 from part 4"

x = matrix('1 1 1 -1')

print "Start with vector \n", x, "\n"

W = x.getT() * x
W = W - eye(W.shape[0])

print "Weigh matrix", W, "\n"

# excersize 2

print "Check for association \n", sign(x * W), "\n"

# excersize 3
x1 = matrix('-1 -1 1 -1')
print "vector x1=", x, "\n"

print "Check for association with x1\n", sign(x1 * W), "\n"
