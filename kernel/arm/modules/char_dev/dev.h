#include <asm/uaccess.h>

static char *str_hello = "Hello from /dev\n";

ssize_t hello_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	int 	err = 0;

	size_t	len = strlen(str_hello);

	if( size < len ) return -EINVAL; 
	if( *ppos != 0 ) return 0;

	err = copy_to_user(buf, str_hello, len);
	if (err)
		return -EFAULT;

	*ppos = len;

	return len;
}
