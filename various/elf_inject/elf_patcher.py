#!/usr/bin/python

import os, sys
import string

from elftools import *
from elftools.common.exceptions import ELFError
from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from elftools.common.py3compat import (
        ifilter, byte2int, bytes2str, itervalues, str2bytes)

class ReadElf(object):
	def __init__(self, file, output):
		self.elffile = ELFFile(file)
		self.output = output

	def show(self):
		print "Num of sections %d" % self.elffile.num_sections()

        	for section in self.elffile.iter_sections():
			if not isinstance(section, SymbolTableSection):
				continue 
			if section['sh_entsize'] == 0:
				print("\nSymbol table '%s' has a sh_entsize of zero!" % (
					bytes2str(section.name)))
				continue

			print("\nSymbol table '%s' contains %s entries:" % (
				bytes2str(section.name), section.num_symbols()))

			for nsym, symbol in enumerate(section.iter_symbols()):
				# symbol names are truncated to 25 chars, similarly to readelf
				print('%d %.25s' % (nsym, bytes2str(symbol.name)))	

def main():
	with open('simple.ko', 'rb') as file:
		try:
			readelf = ReadElf(file, sys.stdout)
			readelf.show()
		except ELFError as ex:
			sys.stderr.write('ELF error: %s\n' % ex)
			sys.exit(1)
	
# ----------------------------
main()
