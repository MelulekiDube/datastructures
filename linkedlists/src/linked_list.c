#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

node_ptr head = NULL;
/**
* This is the only place where we will allocate new memory
*/
node_ptr node_ptr_creator(){
	return (node_ptr)malloc(sizeof(Node));
}

void insert(int d){
	insert_node_tail(d);
}

/**
*Insert the new Node in the head that is the new node
*  becomes the new head.
*/
void insert_node_head(int d){
	node_ptr n= node_ptr_creator();
	n->data = d; n->next = head;
	head = n;
}

/**
*This method inserts to the tail of the list
*/
void insert_node_tail(int d){
	if(!head){
		insert_node_head(d);
		return;
	}
	node_ptr n = node_ptr_creator();
	n->data =d; n->next = NULL;
	node_ptr temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = n;
}

int list_size(node_ptr n){
	int size = 0;
	while(n){
		++size;
		n = n->next;
	}
	return size;
}

/**
* This inserts at node k from the start
*/
void insert_node_k(int k, int d){
	//printf("insert_node_k %i %i", k, d);
	if(k<=0){
		insert_node_head(d);
		return;
	}
	int index = k-1;//the new node will become the new kth
	int c =0;
	node_ptr temp = head;
	while((c!=index)&&(temp)){
		temp = temp->next;
		++c;
	}
	node_ptr n = node_ptr_creator();
	n->data = d; n->next = temp->next;
	temp->next = n;
}

/**
* This methods then insert at node k from the end
*/
void insert_node_k_fromlast(int k, int d){
	//printf("insert_node_k_fromlast %i %i", k, d);
	int s = list_size(head);
	int index = s - k;
	if(index <= 0)
		insert_node_head(d);
	else if(index==s)
		insert_node_tail(d);
	else{
		insert_node_k(index, d);
	}
}

/**
* Method to delete a node with matching value in list
*/
void del_node(int d){
	//printf("Deleting Node\n");
	node_ptr prev = NULL, temp = head;
	while((temp)&&(temp->data!=d)){
		prev = temp;
		temp = temp->next;
	}
	if(temp){
		if(prev){
			prev->next = temp->next;
		}else{
			temp = head;
			head = head->next;
		}
		free(temp); //delete memory in pointer
	}
}

/**
*this is to perfom recursive reversing of list
*/
void _reverse(node_ptr k, node_ptr prev){
	if(!k->next){
		head = k;
		k->next = prev;
		return;
	}
	_reverse(k->next, k);
	k->next = prev;
}

/*
* this is a second reverse function that does not use extra stack or memory
**/
void _reverse2(){
	node_ptr curr = head, prev=NULL, next = curr->next;
	while(curr){
		curr->next = prev;
		prev = curr;
		curr = next;
		if(next)next = next->next;
	}
	head = prev;
}

void reverse(){
	if(head)
		_reverse2();
		//_reverse(head, (node_ptr) NULL);
	else
		printf("Cannot reverse an empty list\n");
}

/*
*method to print the list
*/
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

/*
*
*/
void swap(node_ptr org, node_ptr p){
	int temp = org->data;
	org->data = p->data;
	p->data = temp;
}

/*
* this sorts the linked list
*/
void sort(){
	node_ptr n = head;
	while(n){
		node_ptr min = n, it = n->next;
		while(it){
			if(it->data<min->data)
				min = it;
			it = it->next;
		}
		swap(n, min);
			n = n->next;
	}
}


/*
* Clears the linked_list
*/
void clear(){
	while(head){
		node_ptr temp = head->next;
		free(temp);
		head = temp;
	}
	head = NULL;
}


