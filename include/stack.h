#ifndef stack_H
#define stack_H

/*INCLUDES*/
#include <stdlib.h>
#include <stdbool.h> 
#include "linked_list.h"
#include "base.h"

/*
	@brief A stack pointer that points to a stack object
*/
typedef struct _stack*  stack;

/** 
* @brief The actual stack type
*/
typedef struct _stack{
	/*
	@brief The stack will be built on top of the linked list.
	*/
	linked_list list;
}_stack;

/**creat_stack
* 	Initialized the stack by initializing the list that the stack is built on.
*/
stack creat_stack(void);

/*
*	This functions first checks to see if the stack is empty.	
*   if it is not then it returns the top element in the stack
*	otherwise is report that the stack is empty and returns the value
*	associated with accessing a bad memory address. Utilises the report_empty_error method for this.
*
*/
DATA speek(stack s);

/*
*	First checks if the head is null and if it is prints an error return the error number associated with bad address.
*	If no error it will delete the current head and return the value it head.
*
*/
DATA pop(stack s);

/*
*	This is the stack operation that adds the data item into the top of the stack as the stack is  LIFO
*/
void push(stack s, DATA data);

/**is_qempty:
*	@brief Method to check if the stack is empty
*	@param s The stack we want to check for emptiness
*/
int is_qempty(stack s);
#endif

