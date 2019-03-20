#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"
#include "CUnit/Basic.h"

void test_create();
void insert_test();
void insert_htest();
void delete_test(); //tests both delete_head and del_node
void sort_test();
void reverse_test();

extern int compare(DATA d1, DATA d2);

int test_ll(void){
	 // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_pSuite basic_operations_suit = NULL, other_operatios_suit= NULL;
	// Add a suite to the registry
	basic_operations_suit = CU_add_suite("Test insert and basic operations", 0, 0);
	other_operatios_suit = CU_add_suite("Testing operations like sort and reverse", 0, 0);
	// Always check if add was successful
	if (!(basic_operations_suit&&other_operatios_suit)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(basic_operations_suit, "linked list creation", test_create)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	// Add the test to the suite
	if (!CU_add_test(basic_operations_suit, "insert_test", insert_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(basic_operations_suit, "insert head test", insert_htest)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(basic_operations_suit, "Testing the delete function", delete_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(other_operatios_suit, "Testing the reverse function", reverse_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(other_operatios_suit, "Testing the sorting function", sort_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}

void test_create(){
	linked_list list;
	list = create_ll();
	CU_ASSERT_PTR_NULL(list->head);
	CU_ASSERT_PTR_NOT_NULL(list);
	CU_ASSERT_EQUAL(list->length, 0);
	delete_list(list);
}

//testing insert method which tests insert to tail
void insert_test(){
	linked_list list;
	list = create_ll();
	//test insert
	insert_ll(list,  int_val(0));
	CU_ASSERT_EQUAL(list->head, list->tail);
	insert_ll(list,  int_val(1));
	CU_ASSERT_NOT_EQUAL(list->tail, list->head);
	CU_ASSERT_EQUAL(list->head->data.data_int, 0);
	CU_ASSERT_EQUAL(list->length, 2);
	CU_ASSERT_TRUE(del_node(list, int_val(1), &compare));
	CU_ASSERT_EQUAL(list->length, 1);
	CU_ASSERT_EQUAL(list->head->data.data_int, 0);
	CU_ASSERT_EQUAL(list->head, list->tail);
	for(int i=1;i<10;++i){
		insert_ll(list, int_val(i));
	}
	CU_ASSERT_EQUAL(list->length, 10);
	delete_list(list);
}

void insert_htest(){
	linked_list list;
	list = create_ll();
	
	prepend(list,  int_val(0));
	CU_ASSERT_EQUAL(list->head, list->tail);
	prepend(list, int_val(1));
	CU_ASSERT_EQUAL(list->head->data.data_int, 1);
	CU_ASSERT_EQUAL(list->length, 2);
	for(int i=2;i<10;++i){
		prepend(list, int_val(i));
		CU_ASSERT_EQUAL(list->head->data.data_int, i);
		CU_ASSERT_EQUAL(list->length, i+1);
	}
	delete_list(list);
}

void delete_test(){
	linked_list list;
	list = create_ll();
	//test insert
	insert_ll(list,  int_val(0));
	insert_ll(list,  int_val(1));
	CU_ASSERT_NOT_EQUAL(list->tail, list->head);
	CU_ASSERT_TRUE(del_node(list, int_val(1), &compare));
	CU_ASSERT_EQUAL(list->length, 1);
	CU_ASSERT_EQUAL(list->head->data.data_int, 0);
	CU_ASSERT_EQUAL(list->head, list->tail);
	for(int i=1;i<10;++i){
		insert_ll(list, (int_val(i)));
	}
	for(int i=0;i<9;++i){
		CU_ASSERT_TRUE(delete_head(list));
		CU_ASSERT_EQUAL(list->head->data.data_int, i+1);
		CU_ASSERT_EQUAL(list->length, 9-i);
	}
	CU_ASSERT_EQUAL(list->length, 1);
	CU_ASSERT_EQUAL(list->head->data.data_int, 9);
	CU_ASSERT_EQUAL(list->head, list->tail);
	CU_ASSERT_TRUE(del_node(list, int_val(9), &compare));
	CU_ASSERT_PTR_NULL(list->head);
	CU_ASSERT_PTR_NULL(list->tail);
	delete_list(list);
}

void sort_test(){
	linked_list list;
	list = create_ll();
	int data[] = {100, 12, 19, 0, 12, 100, 90};
	int sorted_data[] = {0, 12, 12, 19 , 90, 100, 100};
	for(int i=0; i<7; ++i){
		insert_ll(list,int_val(data[i]));
	}
	sort(list, &compare);
	node_ptr temp = list->head;
	for(int i=0; i<7; ++i){
		CU_ASSERT_EQUAL(temp->data.data_int, sorted_data[i]);
		temp = temp->next;
	}
	delete_list(list);
}

void reverse_test(){
	linked_list list;
	list = create_ll();
	for(int i=10;i>=0;--i){
		insert_ll(list, int_val(i));
	}
	reverse(list);
	node_ptr temp = list->head;
	for(int i=0;i<11;++i){
		CU_ASSERT_EQUAL(temp->data.data_int, i);
		temp = temp->next;
	}
	delete_list(list);
}