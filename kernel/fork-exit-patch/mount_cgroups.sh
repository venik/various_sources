BLK_GRP=/dev/cgroups/blkio/

mkdir -p $BLK_GRP
mount -t cgroup -oblkio none $BLK_GRP

# WatchDog group
mkdir $BLK_GRP/wdg
