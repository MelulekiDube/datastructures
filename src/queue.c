#include "../include/linked_list.h"
#include "../include/queue.h"

#include <stdio.h>
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
