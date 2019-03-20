#include <stdlib.h>
#include "../include/base.h"
extern int test_ll(void);
extern int test_bst(void);

int compare(DATA d1, DATA d2){
	return d1.data_int<d2.data_int?-1:(d1.data_int==d2.data_int)?0:1;
}


int main(void){
	test_ll();
	test_bst();
	return 0;
}