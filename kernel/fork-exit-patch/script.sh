PATH_CGRP=/dev/cgroups/blkio/wdg

./cgroup_event_listener $PATH_CGRP/tasks 0

if [ $? -ne 0 ]; then
        echo "something unexpected happens"
fi

ps -o pid,ppid,uid,vsz,rss,args -p `cat $PATH_CGRP/cgroup.procs`
