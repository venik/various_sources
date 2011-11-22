qemu-system-arm -initrd ./rootfs.ext2 -kernel ./zImage -append "console=ttyAMA0 root=/dev/ram rw" -serial stdio -M realview-pbx-a9 -m 1024 -cpu cortex-a9 -smp 2 -gdb tcp:1234 -s -S
