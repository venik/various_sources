#!/usr/bin/python

# Alex Nikiforov nikiforov.pub@gmail.com
#
# simple neuro network for solving linear equation y = mx + c
# it use simple Widrow-Hoff rule
#
# GPL v3

#from pylab import *

#learn_set_x = [0.3, 0.35, 0.4, 0.5, 0.6, 0.8, 0.95, 1.1]
#learn_set_t = [1.6, 1.4,  1.40,1.6, 1.7, 2.0, 1.7, 2.10]

learn_set_x = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0]
learn_set_t = [0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5]

nu = 0.3
c = 0.5
m = 0.25

#for i in range(len(learn_set_x)):
for i in range(4):

	x = learn_set_x[i]
	t = learn_set_t[i]

	for k in range(10000):
		#print "x = %01.2f" % learn_set[i][0], " y = %01.2f" % learn_set[i][1]
		y = m * x + c
		delta = t - y
		#print "\t delta = %01.2f" % delta, "t = %01.2f" %t, "y = %01.2f" %y
		print "\t delta = " , delta, "t = %01.2f" %t, "y = %01.2f" %y

		if delta > 100:
			break
		
		# update network
		delta_m = nu * delta * x
		delta_c = nu * delta * 1
		#c = c + delta_c
		m = m + delta_m
		#print "\t m = " , m, " c = ", c
		#print "---------"

print "m = %01.2f" % m, "c = %01.2f" % c

#plot(learn_set_x,learn_set_t)
#show()
