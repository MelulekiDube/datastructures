#include "../include/linked_list.h"
#include "../include/queue.h"
#include "../include/error_handling.h"

/*
* Adds the item to the end of the queue
*/
void add(int item){
	insert_node_tail(item);
}

/*
* 	This methods checks if the queue is empty first. And then attempts to remove the top item returning its value
*
*/
int remove(){
	if(is_empty())
		return report_empty_error();
	int data = get_head()->data;
	delete_head();
	return data;
}

/*
*	This methods checks if the queue is empty first.
*   If not returns the item stored in the top of the queue.
*/
int peek(){
	if(is_empty())
		return report_empty_error();
	return get_head()->data;
}
