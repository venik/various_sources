CC=arm-none-linux-gnueabi-gcc

all: sum.c ex.c
	$(CC) $^ -o ex

asm: sum.c ex.c
	$(CC) -S $^ 

clean:
	rm -f ex core ex.s sum.s
