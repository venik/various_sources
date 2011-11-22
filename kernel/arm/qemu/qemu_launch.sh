qemu-system-arm -kernel ./zImage -append "ip=dhcp console=ttyAMA0 root=/dev/nfs nfsroot=10.0.2.2:/srv/nfs/ rw" -serial stdio -M realview-pbx-a9 -m 1024 -cpu cortex-a9 -smp 2 -redir tcp:2222::22 -redir tcp:1234::1234
#gdb usage -redir tcp:1234::1234
#ssh, scp usage -redir tcp:2222::22