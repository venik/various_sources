#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
# SOFM model from chapter 3, example 3.3 
# GPL v3

from numpy import *

# trace
def make_line():
	print "*" * 20

# distance calculate in eucled form as
# d_j = sum(w_ij - x_i)^2
def calc_dist(w, x):
	d = (	[round(sum([(x.item(0) - w.item(0, 0))**2,
			    (x.item(1) - w.item(1, 0))**2,
                            (x.item(2) - w.item(2, 0))**2]), 3),
		 round(sum([(x.item(0) - w.item(0, 1))**2,
			    (x.item(1) - w.item(1, 1))**2,
			    (x.item(2) - w.item(2, 1))**2]), 3)
		])
	return d

# update weights
# w_ij(n+1) = w_ij(n) + nu * (x_i - w_ij)
def update_weights(w, x):
	w_new = w.T + nu * (x - w.T)
	return w_new.T

def update_iteration(weights, input_vec):

	make_line()
	print "layer = \n", weights
	print "input vector = \n", input_vec
	make_line()

	distance = calc_dist(layer, input_vec)

	make_line()
	print "Distance after the iteration = \n", distance
	make_line()

	if distance[0] <= distance[1]:
		new_layer = update_weights(layer[:,0], input_vec)
		layer[:,0] = new_layer
	else:
		new_layer = update_weights(layer[:,1], input_vec)
		layer[:,1] = new_layer

	make_line()
	print "Updated layer = \n", weights
	make_line()
	
	return weights

nu = 0.5

# Learn vectors 
first_vec   = matrix('0.8 0.7 0.4')
second_vec  = matrix('0.6 0.9 0.9')
third_vec   = matrix('0.3 0.4 0.1')
fourth_vec  = matrix('0.1 0.1 0.3')

# weights
layer = matrix('0.5 0.4; 0.6 0.2; 0.8 0.5')

# Ready-Steady-GOOOO
layer = update_iteration(layer, first_vec)
layer = update_iteration(layer, second_vec)
layer = update_iteration(layer, third_vec)
layer = update_iteration(layer, fourth_vec)

