# $1 - where to mount	(/mnt/image)
# $2 - where to copy	(/srv/nfs)

mount -o loop ./rootfs.ext2 $1
cp -p -a $1/* $2/
umount $1