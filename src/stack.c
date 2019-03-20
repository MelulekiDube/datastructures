#include <stdio.h>
#include "../include/error_handling.h"
#include "../include/stack.h"
#include <stdio.h>


/**creat_stack
* 	Initialized the stack by initializing the list that the stack is built on.
*/
stack creat_stack(void){
	stack temp = (stack) malloc (sizeof(_stack));
	temp->list = create_ll();
	return temp;
}

/*
*	This is the stack operation that adds the data item into the top of the stack as the stack is  LIFO
*/
void push(stack s, DATA data){
	prepend(s->list, data);
}

/*
*	First checks if the head is null and if it is prints an error return the error number associated with bad address.
*	If no error it will delete the current head and return the value it head.
*
*/
DATA pop(stack s){
	if(is_empty(s->list))
		printf("error");
	DATA data = s->list->head->data;
	delete_head(s->list);
	return data;
	
}


/*
*	This functions first checks to see if the stack is empty.	
*   if it is not then it returns the top element in the stack
*	otherwise is report that the stack is empty and returns the value
*	associated with accessing a bad memory address. Utilises the report_empty_error method for this.
*
*/
DATA speek(stack s){
	if(is_empty(s->list))
		printf("error");
	return s->list->head->data;
}

/**is_qempty:
*	@brief Method to check if the stack is empty
*	@param s The stack we want to check for emptiness
*/
int is_sempty(stack s){
	return is_empty(s->list);
}

