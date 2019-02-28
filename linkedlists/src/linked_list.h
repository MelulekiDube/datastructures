#ifndef linke_list_H
#define linke_list_H

#include <stdlib.h>

typedef struct Node* node_ptr;

typedef struct Node{
	int data;
	node_ptr next;
}Node;



void insert(int data);
void insert_node_tail(int data);
void insert_node_head(int data);
void insert_node_k(int k, int data);
void insert_node_k_fromlast(int k, int data);
void del_node(int data);


void sort();
void reverse();
void clear();
int list_size();
void print_list();
#endif