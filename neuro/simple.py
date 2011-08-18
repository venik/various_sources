#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
#
# simple neuro network for solving linear equation y = mx + c
# it use simple Widrow-Hoff rule
#
# GPL v3


learn_set = [[0.3, 1.6], [0.35, 1.4], [0.4, 1.40], [0.5, 1.6], [0.6, 1.7], [0.8, 2.0], [0.95, 1.7], [1.1, 2.10]]
nu = 0.1
c = 0.3
m = 0.3

for i in range(len(learn_set)):
	for k in range(10000):
		#print "x = %01.2f" % learn_set[i][0], " y = %01.2f" % learn_set[i][1]
		x = learn_set[i][0]
		t = learn_set[i][1]
		y = m * x + c
		delta = t - y
		#print "\t delta = %01.2f" % delta, "t = %01.2f" %t, "y = %01.2f" %y
		
		# update network
		delta_m = nu * delta * x
		delta_c = nu * delta * c
		c = c + delta_c
		m = m + delta_m

print "m = %01.2f" % m, "c = %01.2f" % c
