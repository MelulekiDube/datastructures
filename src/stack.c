#include <stdio.h>
#include "../include/error_handling.h"
#include "../include/stack.h"


/*
*	This is the stack operation that adds the data item into the top of the stack as the stack is  LIFO
*/
void push(int data){
	insert_node_head(data);
}

/*
*	First checks if the head is null and if it is prints an error return the error number associated with bad address.
*	If no error it will delete the current head and return the value it head.
*
*/
int pop(){
	if(is_empty())
		return report_empty_error();
	int data = get_head()->data;
	delete_head();
	return data;
	
}


/*
*	This functions first checks to see if the stack is empty.	
*   if it is not then it returns the top element in the stack
*	otherwise is report that the stack is empty and returns the value
*	associated with accessing a bad memory address. Utilises the report_empty_error method for this.
*
*/
int peek(){
	if(is_empty())
		return report_empty_error();
	return get_head()->data;
}



