#include <stdio.h>

#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])

#define SWAP(X, Y, TMP)		\
do {				\
	TMP = X;		\
	X = Y;			\
	Y = TMP;		\
} while(0);

#define PRINT_OUT(ARRAY, K, N)		\
do {					\
	printf("=> ");			\
	for(K=0; K<N; K++) {		\
		printf("%d ", array[K]);\
	}				\
	printf("\n");			\
} while(0);

int main(void)
{
	int	array[] = {4,2,56,32,7,2,6,8,6,3,5,7};
	int j, k, incr, n, tmp;

	n = ARR_SIZE(array);
	incr =  n / 2;

	PRINT_OUT(array, k, n)

	while( incr > 0 ) {
		//printf("-\n");
		for(j=incr; j<n; j++) {
			k = j - incr;
			//printf("+ k = %d k + incr = %d\n", k, k + incr);
			while( k>=0 ) {
				if ( array[k] > array[k + incr]) {
					SWAP(array[k], array[k + incr], tmp)
					k = k - incr;
					//`printf("=\n");
				} else {
					k = -1;
				}
			}
		} // for(i=incr+1; i<n; i++)
		incr = incr / 2;
	} // while( incr > 0 )

	PRINT_OUT(array, k, n)

	return 0;
}
