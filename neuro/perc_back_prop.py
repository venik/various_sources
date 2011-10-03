#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com

# perceptron with back propagation correction
# 2-2-2-1 architecture

# GPL v3

from numpy import *

def activate_function(net_j):
	return 1 / (1 + exp(-net_j))

# weight of the layers
First_layer  = matrix('2 2; -2 3; -2 3')
Second_layer = matrix('3 -2; -2 2; -4 2')
Third_layer  = matrix('-2; 3; 1')

# norm of the learning
nu = 0.8

# input data
input_v1 = matrix('1 0.1 0.9')

print "First layer = \n", First_layer
print "Second layer = \n", Second_layer
print "Third layer = \n", Third_layer

print "\n==============================\n"

# first layer 
first_res = input_v1 * First_layer

input_v2 = matrix([	1,
			round(activate_function(first_res.item(0)), 3),
			round(activate_function(first_res.item(1)), 3)])

print "first layer output = \n", input_v2 

print "\n==============================\n"

# second layer 
second_res = input_v2 * Second_layer

input_v3 = matrix([	1,
			round(activate_function(second_res.item(0)), 3),
			round(activate_function(second_res.item(1)), 3)])

print "second layer output = \n", input_v3 

print "\n==============================\n"

# third layer 
third_res = input_v3 * Third_layer

input_v4 = round(activate_function(third_res.item(0)), 3)

print "third layer output = ", input_v4 
