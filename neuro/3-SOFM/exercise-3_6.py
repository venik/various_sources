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

def upd_euc_weights(w, x, nu):
	w_new = w + nu * (x - w)	
	return w_new

# scalar helper
def csd(p, x):
	return sqrt(p**2 + x**2)

# scalar distance 
def calc_scalar_distance(p, x):
	dist = (p[0] * x[0] + p[1] * x[1]) / (csd(p[0], x[0]) * csd(p[1], x[1]))
	return dist

def s_vec_norm(vec):
	denominator = round(sqrt(vec[0]**2 + vec[1]**2 + vec[2]**2), 3)
	#print "denominator ", denominator
	vec_norm = vec / denominator
	return vec_norm

def upd_scalar_weights(w, x, nu):
	w_norm = s_vec_norm(w)
	x_norm = s_vec_norm(x)

	w_new = w_norm + nu * x_norm
	denominator = sqrt(w_new[0]**2 + w_new[1]**2 + w_new[2]**2)
	w_new = w_new / denominator
	w_new[0] = round(w_new[0], 3)
	w_new[1] = round(w_new[1], 3)
	w_new[2] = round(w_new[2], 3)

	return w_new

##################################################
# defenitions
##################################################
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
	p_e_win = p2
elif e_x_p1 < e_x_p2: 
	print "x closer to p1 rather than p2 in euclid mean"
	p_e_win = p1
else:
	print "euclid distance the same"
	p_e_win = p2
tline()

# b - calculate scalar distance
s_x_p1 = calc_scalar_distance(p1, x)
s_x_p2 = calc_scalar_distance(p2, x)

tline()
print "scalar distanse x-p1=>", s_x_p1
print "scalar distanse x-p2=>", s_x_p2
if s_x_p1 > s_x_p2:
	print "x closer to p1 rather than p2 in scalar mean"
	s_x_win = p1
elif s_x_p1 < s_x_p2: 
	print "x closer to p2 rather than p1 in scalar mean"
	s_x_win = p2
else:
	print "scalar distance the same"
	s_x_win = s_x_p1
tline()

# v - correct weight in euclid mean with nu = 0.8 
tline()
nu = 0.8
p_e_new = upd_euc_weights(p_e_win, x, nu)
print "new weights in euclid mean =>\n", p_e_new
tline()

# g - correct weight in scalar mean with nu = 0.8 
tline()
nu = 0.8
p_e_new = upd_scalar_weights(s_x_win, x, nu)
print "new weights in euclid mean =>\n", p_e_new
tline()
