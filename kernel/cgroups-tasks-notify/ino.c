#include <stdio.h>
#include <sys/inotify.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include <trace.h>

FILE *I;

int main(int argc, char **argv)
{
	int 	i_fd, w_fd;
	char	f_name[255];

	int	res, ie_size = 256 * (sizeof(struct inotify_event) + 16);		/* + len */
	struct inotify_event *ie = malloc(ie_size);

	I = stdout;

	if( argc < 2 )  {
		TRACE(0,"./ino file-for-watch\n");
		return -1;
	}

	// FIXME
	snprintf(f_name, 255, argv[1]);

	/* init inotify subsystem */
	i_fd = inotify_init();
	if( i_fd < 0 ) {
		ETRACE("[ERR] Cannot init inotify. errno: ");
		return -1;
	}

	w_fd = inotify_add_watch(i_fd, f_name, IN_MODIFY|IN_ATTRIB);
	if( w_fd < 0 ) {
		ETRACE("[ERR] Cannot inotify fd event. errno: ");
		return -1;
	}

	TRACE(0, "name of file for inotify %s\n", f_name);

	do {
		res = read(i_fd, ie, ie_size);
		TRACE(0, "%s(): readed %d bytes\n", __func__, res);
		if(ie->mask & IN_MODIFY) {
			TRACE(0, "fd:%02d\tIN_MODIFY\n", ie->wd);
		}
	} while(1);

	return 0;
}
