#ifndef linked_list_H
#define linked_list_H
#include <stdlib.h>
#include "base.h" 

/*
	@brief Defining a new type node_ptr to avoid the need to having to type struct Node* every time to refer to a node pointer
*/
typedef struct Node* node_ptr;
typedef struct ll* linked_list;

/*
	@brief This is a node structure that will be the basis unit of creating the linked list`
	Data is the data that a node will contain
	next  is the next node following this one.
*/
typedef struct Node{
	/*
		@brief The data that is stored in the node
	*/
	DATA data;
	/**
		@brief A link or pointer to the next node.
	*/
	node_ptr next;
}Node;


/*
	@brief The actual linked list type that will contain the head of the linked list and the length of the linked list.
*/
typedef struct ll{
	/**
		@brief The node at the top of this linked list.
	*/
	node_ptr head;
	
	/*
		@brief the node at the bottom of this list. That is the last node in the list.
	*/
	node_ptr tail;
	
	/*
		@brief This is how many nodes this list holds.
	*/
	int length;
}ll;

/*
	@brief This method will create a new linked list and initialize its head to NULL
	@returns the new pointer to the new linked list.
*/
linked_list create_ll(void); 

/*
	@brief This is more of a private method that creates a new linked list Node on the heap.
	@returns the pointer to the new linked-list object created
*/
node_ptr node_ptr_creator();

/*
	@brief This method will append to the linked list specified.
	@param list is the list to append to.
	@param data, is the data that we are appending to the newly created linked list.
*/
void insert_ll(linked_list list, DATA data);

/*
	@brief This methods appends that is adds a new Node to the end of the list.
	@param list is the list that we are appending to.
	@param data is the data that we are appending to the list.
*/
void append(linked_list list, DATA data);

/*
	@brief This method does the same thing as append but will rather add onto the top of the list. This method then changes the head of the list.
	@param list  is the list that we are perpending to.
	@param data is the data that we are prepending to the list.
*/
void prepend(linked_list, DATA data);

/*
	@brief This methods adds a new data item to the kth position from the start of the list.
	@param list the list that we are adding data to.
	@param k the position from the head of the list that we are putting data to
		if k is more than the length of the list we then insert at the tail
	@data the new data we are adding to the list.
*/
void prepend_atk(linked_list, int k , DATA);

/*

	@brief This methods adds a new data item to the kth position from the end of the list.
	@param list the list that we are adding data to.
	@param k the position from the head of the list that we are putting data to
		if k is more than the length of the list we then insert at the head
	@data the new data we are adding to the list.
*/
void append_atk(linked_list list, int k, DATA data);

/*
	@brief This method deletes the head of the list. 
	@param list the list that we want to delete the head from.
	@param comp the comparator function that we will use to compare the data.
	@returns a non-zero value if the deletion was complete and zero if there was an error
*/
int delete_head(linked_list list);

/*
	@brief This method deletes the node with data of the list.
	@param list is the list we are deleting from.
	@param data the data we are deleting from the list.
	@param comp the comparator function that we will use to compare the data.
	@returns a non-zero value if the deletion was complete and zero if there was an error
*/
int del_node(linked_list list, DATA data, DATA_COMPARE comp);


/*
	@brief This method will sort the list.
	@param list the list to be sorted
	@param comp the comparator function that we will use to compare the data.
*/
void sort(linked_list list, DATA_COMPARE comp);

/*
	@brief This method will reverse the list. That the tail of the list is now the head and the head now the tail.
*/
void reverse(linked_list list);

/*
	@brief This method will clear the list.
	@param the list to be cleared
*/
void clear(linked_list list);


/*
	Method will check if the list is empty. 
	@param list to evaluate if empty
	@returns True that is a 1 if empty and 0 if not empty
*/
int is_empty(linked_list list);

/*
	@brief This is a function that will clear and delete the linked list instance from the heap.
*/
void delete_list(linked_list list);
#endif