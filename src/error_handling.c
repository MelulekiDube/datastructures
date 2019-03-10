#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/error_handling.h"
/*
*	This method reports that the stack is empty and return a bad value error number in relations to trying to access a null pointer.
*
*/
int report_empty_error(){
	int errnum;
	errnum = EFAULT;
	fprintf(stderr,"The data structure is empty is empty %s\n", strerror( errnum ));
	return errnum;
}