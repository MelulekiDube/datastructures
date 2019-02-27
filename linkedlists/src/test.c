#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

void test_print_list(){
	printf("List now: ");print_list();
}

void test_del(int d){
	printf("performing del of %i\n",d);
	del_node(d);
	test_print_list();
}

void test(){
	test_del(0);
	printf("Inserting to 0\n");insert_node_k(0, 0);
	test_print_list(); //expect 0....9
	test_del(0);
	printf("Inserting to 0\n");insert_node_k_fromlast(9, 0);
	test_print_list();
	test_del(9);
	printf("Inserting to 9\n");insert_node_k_fromlast(0, 9);
	test_print_list();
	test_del(9);
	printf("Inserting to 0\n");insert_node_k(9, 9);
	test_print_list();
}

int main(int argc, char *args[]){
	for(int i=0; i < 10; ++i){
		insert(i);
	}
	test_print_list();
	test();
}