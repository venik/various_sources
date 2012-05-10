# Path
ROOT=./
KDIR=$(ROOT)/linux-kernel

PWD = $(shell pwd) 
DEST = ./ 

ARCH=arm

TARGET = simple
obj-m      := $(TARGET).o 

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules 

clean:
	@rm -f *.o .*.cmd .*.flags *.mod.c *.order
	@rm -f .*.*.cmd *.symvers *~ *.*~ TODO.*
	@rm -fR .tmp*
	@rm -rf .tmp_versions
	@rm -f *.ko
