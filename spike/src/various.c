#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <errno.h>

/*
*	
*/
int get_number(int x){
	int errnum;
	if(x%2){
		errnum = errno;
		fprintf(stderr, "Stack is empty\n");
		return EFAULT;
	}
	return x;
}
int main(void) {
  printf("%i \n", get_number(3));
  return 0;
}