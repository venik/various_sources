#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
# SOFM model from chapter 3, example 3.4 
# GPL v3

from numpy import *

def trace():
	print "*" * 20

# calculate distance in scalar form as
# d_j = sum(v_i * w_i) / ( sqrt(v_1^2 + ... v_n^2) * sqrt(w_1^2 + ... w_n^2))
def calc_dist(w, x):
	y = round((w[0] * x[0] + w[1] * x[1]) / (sqrt(x[0]**2 + x[1]**2) * sqrt(w[0]**2 + w[1]**2)), 3)
	return y

def norm_vec(x):
	print "NOT normalized =>\n", x
	denominator = sqrt(x[0]**2 + x[1]**2)
	x = x / denominator
	normalized_vec = ([round(x[0], 3), round(x[1], 3)])
	print "normalized =>\n", normalized_vec
	return normalized_vec

def update_weight(w, x):
	trace()
	print "Update weight"
	print "before update =>\n", w
	w_new = mat(w) + nu * x
	denominator = sqrt(w_new[0,0]**2 + w_new[0,1]**2)
	w_new = w_new / denominator
	w_new = ([round(w_new[0,0],3), round(w_new[0,1],3)])
	print "after update =>\n", w_new
	trace()
	return w_new

a  = matrix('1;4')
p1 = matrix('2;1')
p2 = matrix('6;6')

nu = 1

dist1 = calc_dist(p1, a)
dist2 = calc_dist(p2, a)

trace()
print "distance to p1=>", dist1
trace()
print "distance to p2=>", dist2

a  = norm_vec(a)
#p1 = norm_vec(p1)
p2 = norm_vec(p2)

trace()
p2 = update_weight(p2, a)
p2 = update_weight(p2, a)
