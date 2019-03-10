#ifndef linke_list_H
#define linke_list_H

#include <stdlib.h>
#include <stdbool.h>
 
typedef struct Node* node_ptr;

typedef struct Node{
	int data;
	node_ptr next;
}Node;

node_ptr node_ptr_creator();

void insert(int data);
void insert_node_tail(int data);
void insert_node_head(int data);
void insert_node_k(int k, int data);
void insert_node_k_fromlast(int k, int data);
void delete_head(void);
void del_node(int data);
node_ptr get_head(void);
void sort(void);
void reverse(void);
void clear(void);
int list_size(node_ptr node);
void print_list(void);

bool is_empty();
#endif