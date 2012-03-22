#!/bin/sh

PID=$$
BLK_GRP=/dev/cgroups/blkio/

# move self PID to the WDG, every child will be in the WDG group
echo "my pid $PID"
echo $PID >>  $BLK_GRP/wdg/tasks

# fork child
sleep 600 &
SLP_PID=$!

echo "sleep PID:$SLP_PID"
