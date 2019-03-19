#ifndef queue_H
#define queue_H

//INCLUDES
#include <stdlib.h>
#include "../include/linked_list.h"
typedef struct _queue* queue;

struct _queue{
	linked_list list;
};

void enque (queue q, DATA d);// Add an item to the end of the list.
DATA deque (queue q);//Remove the first item in the list.
DATA qpeek (queue q);//: Return the top of the queue.
#endif