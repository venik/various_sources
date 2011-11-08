#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

static int write_call(char* buf, int n )
{
   volatile int block[2];
   block[0] = (int)buf;
   block[1] = n;

   __asm__ volatile (
      "mov  r0, #1\n\t"        	/* stdout */
      "ldr  r1, [%0]\n\t"      	/* buf */
      "ldr  r2, [%0, #4]\n\t"  	/* n */
      "mov  r7, #4\n\t"		/* __NR_write */
      "svc  0x0\n"          	/* write() */
      "str  r0, [%0]\n\t"
      :
      : "r" (block)
      : "r0","r1","r2","r7"
   );
   if (block[0] < 0)
      block[0] = -1;

   return block[0];
}

void do_write( void ) { 
	char *str = "write syscall string!\n"; 
	int len = strlen( str ) + 1, n;
	printf( "string for write length = %d\n", len ); 
	n = write_call(str, len); 
	printf( "write return :%d\n", n ); 
} 

int main(void)
{
	do_write();
	return 0;	
}
