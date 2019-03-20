#include "../include/linked_list.h"
#include "../include/queue.h"

#include <stdio.h>


/**creat_queue
* 	Initialized the queue by initializing the list that the stack is built on.
*/
queue creat_queue(void){
	queue temp = (queue) malloc (sizeof(_queue));
	temp->list = create_ll();
	return temp;
}

/*
* Adds the item to the end of the queue
*/
void enque(queue q, DATA item){
	append(q->list, item);
}

/*
* 	This methods checks if the queue is empty first. And then attempts to remove the top item returning its value
*
*/
DATA deque(queue q){
	if(is_empty(q->list))
		//throw error_handling
		printf("error");
	DATA data = q->list->head->data;
	delete_head(q->list);
	return data;
}

/*
	This methods checks if the queue is empty first. If not returns the item stored in the top of the queue.
*/
DATA qpeek(queue q){
	if(is_empty(q->list))
		printf("error");
	return q->list->head->data;
}

/**is_qempty:
*	@brief Method to check if the queue is empty
*	@param q The queue we want to check for emptiness
*/
int is_qempty(queue q){
	return is_empty(q->list);
}
