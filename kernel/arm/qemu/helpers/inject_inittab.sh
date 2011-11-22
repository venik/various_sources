mount -o loop ./rootfs.ext2 /mnt/tmp
cp ./inittab /mnt/tmp/etc/
umount /mnt/tmp/
