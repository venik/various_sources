KDIR=./linux-kernel
PWD = $(shell pwd) 

obj-m = nullderef.o

nullderef.ko: nullderef.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	@rm -rf	.tmp_versions	\
		*.o *.ko	\
		nullderef.ko	\
		nullderef.mod.c \
		nullderef.mod.o \
		nullderef.o 	\
		.nullderef.ko.cmd	\
		.nullderef.mod.o.cmd \
		.nullderef.o.cmd 	\
		modules.order	\
		Module.symvers
