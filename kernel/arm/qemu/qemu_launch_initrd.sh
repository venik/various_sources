qemu-system-arm -initrd ./rootfs.ext2 -kernel ./zImage -append "console=ttyAMA0 root=/dev/ram rw" -serial stdio -M realview-pbx-a9 -m 1024 -cpu cortex-a9 -smp 2 -redir tcp:2222::22 -redir tcp:1234::1234
#gdb usage -redir tcp:1234::1234
#ssh, scp usage -redir tcp:2222::22
