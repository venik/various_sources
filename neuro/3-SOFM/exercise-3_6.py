#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
# Chapter 3, exercise 1 
# GPL v3

from numpy import *

def tline():
	print "*" * 50

# euclid helper
def ced(p, x):
	return ((p - x)**2)

# euclid distance
def calc_euc_dist(p, x):
	dist = ced(p[0], x[0]) + ced(p[1], x[1]) + ced(p[2], x[2])
	return dist

# scalar helper
def csd(p, x):
	return sqrt(p**2 + x**2)

# scalar distance 
def calc_scalar_distance(p, x):
	dist = (p[0] * x[0] + p[1] * x[1]) / (csd(p[0], x[0]) * csd(p[1], x[1]))
	return dist

# defenitions
#x  = matrix('0.2 -1.4 2.3')
x  = matrix('0.2; -1.4; 2.3')
p1 = matrix('0.6; -4.0; 7.0')
p2 = matrix('0.1; -1.0; 2.2')

# a - calculate euclidian distance
e_x_p1 = calc_euc_dist(p1, x)
e_x_p2 = calc_euc_dist(p2, x)

tline()
print "euclid distanse x-p1=>", e_x_p1
print "euclid distanse x-p2=>", e_x_p2
if e_x_p1 > e_x_p2:
	print "x closer to p2 rather than p1 in euclid mean"
elif e_x_p1 < e_x_p2: 
	print "x closer to p1 rather than p2 in euclid mean"
else:
	print "euclid distance the same"
tline()

# b - calculate scalar distance
s_x_p1 = calc_scalar_distance(p1, x)
s_x_p2 = calc_scalar_distance(p2, x)

tline()
print "scalar distanse x-p1=>", s_x_p1
print "scalar distanse x-p2=>", s_x_p2
if s_x_p1 > s_x_p2:
	print "x closer to p1 rather than p2 in scalar mean"
elif s_x_p1 < s_x_p2: 
	print "x closer to p2 rather than p1 in scalar mean"
else:
	print "scalar distance the same"
	
tline()
