#CC=gcc
CC=arm-none-linux-gnueabi-gcc

CFLAGS=-Wall -g
LIBS=

LIBS_WD_WP+=$(LIBS)
CFLAGS_WD_WP+=$(CFLAGS)

all: cgroup_event_listener

cgroup_event_listener: cgroup_event_listener.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY:	clean tags

tags:
	@ctags -R *
clean:
	@rm -f core cgroup_event_listener
