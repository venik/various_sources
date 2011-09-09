/* check for loop in a linked list with O(N) complexity */
/* I took the idea from linkedin.com discussion */

/* Alex Nikiforov nikiforov.alex@rf-lab.org */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define	LIST_LENGTH 16
#define LOOP 0

typedef struct list_s list_t;

struct list_s {
	uint8_t		num;
	list_t		*next;
};

int main(void)
{
	int 		i;
	list_t		my_list[LIST_LENGTH], *p_my_list;

	p_my_list = my_list;

	for(i=0; i<LIST_LENGTH - 2; i++) {
		printf("i=%d\n", i);
		p_my_list->num = i;
		p_my_list->next = p_my_list + 1;
		p_my_list = p_my_list->next;
		
	}

#if LOOP == 1
	printf("LOOPED\n");
	p_my_list->next = my_list + 5;
#else
	printf("Without any loop\n");
	p_my_list->next = NULL;
#endif

	/* FIXME - here we should to check p_my_list2->next for NULL */
	/* but I'm too lazy */

	/* search algo with 2 pointers */
	list_t		*p_my_list2 = my_list;

	p_my_list = p_my_list2;

	do {
		printf("p_my_list = %p p_my_list2 = %p\n", p_my_list, p_my_list2);

		p_my_list = p_my_list->next;
		p_my_list2 = p_my_list2->next->next;

	} while( (p_my_list2->next != NULL) && (p_my_list2 != p_my_list) );

	if( p_my_list2->next == NULL ) {
		printf("there is no any loop\n");
	} else {
		printf("we have loop\n");
	}

	return 0;
}
