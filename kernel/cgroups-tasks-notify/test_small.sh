#!/bin/sh

PID=$$
BLK_GRP=/dev/cgroups/blkio/

# move self PID to the WDG, every child will be in the WDG group
echo "my pid $PID"
echo $PID >>  $BLK_GRP/wdg/tasks

sleep 3 &
SLP_PID=$!

# now we will get 4 inotify event (1 for adding current test in wdg, one for sleep start,
# one for sleep end and one for finish current test)
