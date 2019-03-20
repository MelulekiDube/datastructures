#ifndef queue_H
#define queue_H

//INCLUDES
#include <stdlib.h>
#include "../include/linked_list.h"
typedef struct _queue* queue;

typedef struct _queue{
	linked_list list;
}_queue;


/**creat_queue
* 	Initialized the queue by initializing the list that the stack is built on.
*/
queue creat_queue(void);

/*
* Adds the item to the end of the queue
*/
void enque(queue q, DATA item);// Add an item to the end of the list.

/*
* 	This methods checks if the queue is empty first. And then attempts to remove the top item returning its value
*
*/
DATA deque(queue q);//Remove the first item in the list.

/*
	This methods checks if the queue is empty first. If not returns the item stored in the top of the queue.
*/
DATA qpeek(queue q);//: Return the top of the queue.

/**is_qempty:
*	@brief Method to check if the queue is empty
*	@param q The queue we want to check for emptiness
*/
int is_qempty(queue q);
#endif