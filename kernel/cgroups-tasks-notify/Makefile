CC=arm-none-linux-gnueabi-gcc

CFLAGS=-Wall -g
INCLUDE=-I../../src/include/

all: ino

ino: ino.c
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

.PHONY:	clean tags

tags:
	@ctags -R *
clean:
	@rm -f core ino 
