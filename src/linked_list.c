#include <stdio.h>
#include "../include/linked_list.h"

/*
	@brief This method will create a new linked list and initialize its head to NULL and tail
	@returns the new pointer to the new linked list.
*/
linked_list create_ll(){
	linked_list temp = (linked_list)malloc(sizeof(ll));
	temp->head = temp->tail = NULL;
	temp->length = 0;
	return temp;
}

/**
* This is the only place where we will allocate new memory
*/
node_ptr node_ptr_creator(){
	return (node_ptr)malloc(sizeof(Node));
}

void insert(linked_list list, DATA d){
	append(list, d);
}

/**
*Insert the new Node in the head that is the new node
*  becomes the new head.
*/
void prepend(linked_list list, DATA d){
	node_ptr n= node_ptr_creator();
	n->data = d; n->next = list->head;
	list->head = n;
	if(!list->tail){
		list->tail = list->head;
	}
	list->length++;
}

/**
*This method inserts to the tail of the list
*/
void append(linked_list list, DATA d){
	if(!list->head){
		prepend(list, d);
		return;
	}
	node_ptr n = node_ptr_creator();
	n->data =d; n->next = NULL;
	list->tail->next = n;
	list->tail = n;
	list->length++;
}

/*
	@brief This methods adds a new data item to the kth position from the start of the list.
	@param list the list that we are adding data to.
	@param k the position from the head of the list that we are putting data to
		if k is more than the length of the list we then insert at the tail
	@data the new data we are adding to the list.
	
*/
void prepend_atk(linked_list list, int k, DATA d){
	if(k<=0){
		prepend(list, d);
		return;
	}
	int index = k-1;//the new node will become the new kth
	int c =0;
	node_ptr temp = list->head;
	while((c!=index)&&(temp)){
		temp = temp->next;
		++c;
	}
	node_ptr n = node_ptr_creator();
	n->data = d; n->next = temp->next;
	temp->next = n;
	list->length++;
}

/*

	@brief This methods adds a new data item to the kth position from the end of the list.
	@param list the list that we are adding data to.
	@param k the position from the head of the list that we are putting data to
		if k is more than the length of the list we then insert at the head
	@data the new data we are adding to the list.
*/
void append_atk(linked_list list, int k, DATA data){
	int s = list->length;
	int index = s - k;
	if(index <= 0)
		prepend(list, data);
	else if(index==s)
		append(list, data);
	else{
		prepend_atk(list, index, data);
	}
}


/**
* Method to delete a node with matching value in list

*/
int del_node(linked_list list, DATA d, DATA_COMPARE comp){
	//printf("Deleting Node\n");
	node_ptr prev = NULL, temp = list->head;
	while((temp)&&(comp(d, temp->data))){
		prev = temp;
		temp = temp->next;
	}
	if(temp){
		if(prev){
			if(prev->next == list->tail){
				list->tail = prev;
			}
			prev->next = temp->next;
		}else{
			temp = list->head;
			list->head = list->head->next;
			if(list->head&&!list->head->next)
				list->tail = list->head;
			else if(!list->head)
				list->tail = NULL;
		}
		free(temp); //delete memory in pointer
		list->length--;
		return 1;
	}
	return 0;
}

int delete_head(linked_list list){
	if(!is_empty(list)){
		node_ptr temp = list->head;
		list->head = list->head->next;
		if(is_empty(list))
			list->tail = NULL;
		free(temp);
		list->length--;
		return 1;
	}
	return 0;
}

/**
	This is to performs recursive reversing of list
*/
void _reverse(linked_list list, node_ptr k, node_ptr prev){
	if(!k->next){
		list->head = k;
		k->next = prev;
		return;
	}
	_reverse(list, k->next, k);
	k->next = prev;
}

/*
* this is a second reverse function that does not use extra stack or memory
**/
void _reverse2(linked_list list){
	node_ptr curr = list->head, prev=NULL, next = curr->next;
	while(curr){
		curr->next = prev;
		prev = curr;
		curr = next;
		if(next)next = next->next;
	}
	list->head = prev;
}

void reverse(linked_list list){
	if(list->head)
		_reverse2(list);
		//_reverse(head, (node_ptr) NULL);
	else
		printf("Cannot reverse an empty list\n");
}

/*
*method to print the list
*/
/*
void print_list(){
	node_ptr temp = head;
	while(temp){
		printf("%i",temp->data);
		if((temp=temp->next))
			printf(", ");
		else
			printf("\n");
	}
}
*/

/*
*
*/
void swap(node_ptr org, node_ptr p){
	DATA temp = org->data;
	org->data = p->data;
	p->data = temp;
}

/*
	@brief This method will sort the list.
	@param list the list to be sorted
	@param the function pointer to a comparator fuction that will compare two data values. if this value is null an error will be throw.
*/
void sort(linked_list list, DATA_COMPARE comp){
	if(comp){
		node_ptr n = list->head;
		while(n){
			node_ptr min = n, it = n->next;
			while(it){
				if(comp(it->data,min->data)<0)
					min = it;
				it = it->next;
			}
			swap(n, min);
				n = n->next;
		}
	}
}

/*
	@brief This method will clear the list.
	@param the list to be cleared
*/
void clear(linked_list list){
	while(list->head){
		node_ptr temp = list->head->next;
		free(temp);
		list->head = temp;
	}
	list->tail  = NULL;
}


/*
	Method will check if the list is empty. 
	@param list to evaluate if empty
	@returns True that is a 1 if empty and 0 if not empty
*/
int is_empty(linked_list list){
	return (!list->head);
}

/*
	@brief This is a function that will clear and delete the linked list instance from the heap. That after this, the linked list node that was passed to this function will be null
*/
void delete_list(linked_list list){
	clear(list);
	free(list);
	list = NULL;
}