#ifndef stack_H
#define stack_H

//INCLUDES
#include <stdlib.h>
#include <stdbool.h> 
#include "linked_list.h"
#include "base.h"

typedef struct _stack*  stack;

struct _stack{
	linked_list list;
}_stack;

DATA speek(stack s);
DATA pop(stack s);
void push(stack s, DATA data);
#endif

