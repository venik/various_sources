# Path
ROOT=./
KDIR=$(ROOT)/linux-kernel

PWD = $(shell pwd) 
DEST = ./ 

ARCH=arm

obj-m      := simple.o simple2.o simple3.o evil.o simple4.o evil4.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules 

clean:
	@rm -f *.o .*.cmd .*.flags *.mod.c *.order
	@rm -f .*.*.cmd *.symvers *~ *.*~ TODO.*
	@rm -fR .tmp*
	@rm -rf .tmp_versions
	@rm -f *.ko
