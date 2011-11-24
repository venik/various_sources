#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
# Chapter 3, exercise 8 
# GPL v3

from numpy import *

def tline():
	print "*" * 50

def calc_weight(weights, vec):
	return vec * weights

def net_iteration(vec_1, vec_2, vec_3):
	new_w_1 = calc_weight(weights, to_1)
	new_w_2 = calc_weight(weights, to_2)
	new_w_3 = calc_weight(weights, to_3)

	print "=>\n", new_w_1
	print "=>\n", new_w_2
	print "=>\n", new_w_3

	print "upd vec 1\n"
	if new_w_1 < 0:
		weights[0] = 0
	else:
		weights[0] = new_w_1
	
	if new_w_2 < 0:
		print "upd vec 1\n"
		weights[1] = 0
	else:
		weights[1] = new_w_2
	
	if new_w_3 < 0:
		print "upd vec 1\n"
		weights[2] = 0 
	else:
		weights[2] = new_w_3

	print "weights:\n", weights
	
	return 0

# defenitions
weights = matrix('0.5; 0.2; 0.6');
to_1 = matrix('1 -0.5 -0.5')
to_2 = matrix('-0.5 1 -0.5')
to_3 = matrix('-0.5 -0.5 1')

net_iteration(to_1, to_2, to_3)
net_iteration(to_1, to_2, to_3)

# Next task
tline()
weights = matrix('0.7; 0.6; 0.3');
net_iteration(to_1, to_2, to_3)
net_iteration(to_1, to_2, to_3)
