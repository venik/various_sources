CC=arm-none-linux-gnueabi-gcc

all: sum.c ex.c
	$(CC) $^ -o ex

all_asm: sum.s ex.c
	$(CC) $^ -o ex_from_asm

asm: sum.c ex.c
	$(CC) -S $^ 

sum.s: sum.c
	$(CC) -S $^ 

clean:
	rm -f ex ex_from_asm core *.s
