#!/usr/bin/env python

import numpy as np

last_x = 0
last_y = 1
pi_eval = 0
for x in np.linspace(0, 1, 100):
	y = np.sqrt(1 - x**2)
	dist = np.sqrt( (x - last_x)**2 + (y - last_y)**2 )
	pi_eval += dist

	last_x = x
	last_y = y

print(str(pi_eval * 2))