#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com

# perceptron with back propagation correction
# 2-2-2-1 architecture

# GPL v3

from numpy import *

def activate_function(net_j):
	return 1 / (1 + exp(-net_j))

def back_activate_function(o_j, sum_delta_j_weight_j):
	return o_j * (1 - o_j) * sum_delta_j_weight_j

def correct_weights(w, nu, o_j, delta_j):
	val = nu * o_j * delta_j + w
	return round(val , 4)

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

###########################################################
# backpropagation error correction
###########################################################

print "\n##################################################\n"

desired_output = 0.9

# backcorrection oth the 3rd layer
# delta = (desire_output - output) * output * (1 - output) 

delta = round((desired_output - input_v4) * input_v4 * (1 - input_v4), 3)

print "delta = ", delta

print "\n==============================\n"

back_res = delta * Third_layer

print "layer 3 before correction ", back_res

output_v3 = matrix([ 
		round(back_activate_function(input_v3.item(1), back_res.item(1)), 3),
		round(back_activate_function(input_v3.item(2), back_res.item(2)), 3)])

print "layer 3 after correction ", output_v3 

print "\n==============================\n"

back_res2 = output_v3 * Second_layer.getT()

print "layer 2 before correction ", back_res2 

output_v2 = matrix([ 
		round(back_activate_function(input_v2.item(1), back_res2.item(1)), 3),
		round(back_activate_function(input_v2.item(2), back_res2.item(2)), 3)])

print "layer 2 after correction ", output_v2 

print "\n==============================\n"

###########################################################
# correct weights 
###########################################################

print "\n##################################################\n"

First_layer  = matrix([
	[correct_weights(First_layer.item(0,0), nu, input_v1.item(0), output_v2.item(0)),
	 correct_weights(First_layer.item(0,1), nu, input_v1.item(0), output_v2.item(1))],
	[correct_weights(First_layer.item(1,0), nu, input_v1.item(1), output_v2.item(0)),
	 correct_weights(First_layer.item(1,1), nu, input_v1.item(1), output_v2.item(1))],
	[correct_weights(First_layer.item(2,0), nu, input_v1.item(2), output_v2.item(0)),
	 correct_weights(First_layer.item(2,1), nu, input_v1.item(2), output_v2.item(1))]
	 ])

print "New weights of the first layer \n", First_layer
