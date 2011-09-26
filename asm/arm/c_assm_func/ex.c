#include <stdio.h>

__attribute__((regparm(0))) int sum(int a, int b);

int main(void)
{
	int a=5, b=2, c;

	c = sum(a,b);
	printf("c=%d\n", c);
}
