#include <stdio.h>
#include <stdint.h>

uint8_t populate32(int32_t val)
{
	val = (val & 0x55555555) +  ((val >> 1)  & 0x55555555);
	val = (val & 0x33333333) +  ((val >> 2)  & 0x33333333);
	val = (val & 0x0f0f0f0f) +  ((val >> 4)  & 0x0f0f0f0f);
	val = (val & 0x00ff00ff) +  ((val >> 8)  & 0x00ff00ff);
	val = (val & 0x0000ffff) +  ((val >> 16) & 0x0000ffff);

	printf("val %d\n", val);
	return val;
}

int main(void)
{
	populate32(0xffffffff);
	return 0;
}
