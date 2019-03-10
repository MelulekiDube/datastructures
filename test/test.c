#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"
#include "CUnit/Basic.h"

void insert_test();
void inser_head_test();

int main(int argc, char *args[]){
	 // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_pSuite pSuite = NULL;
	// Add a suite to the registry
	pSuite = CU_add_suite("Test insert", 0, 0);
	// Always check if add was successful
	if (!pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	// Add the test to the suite
	if (!CU_add_test(pSuite, "insert_test", insert_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (!CU_add_test(pSuite, "insert_head_test", inser_head_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}

//testing insert method which tests insert to tail
void insert_test(){
	//assert the head is originally null
	CU_ASSERT_PTR_NULL(get_head());
	//test insert
	insert(0);
	insert(1);
	CU_ASSERT_PTR_NOT_NULL(get_head());
	CU_ASSERT(get_head()->data == 0);
	CU_ASSERT(get_head()->next->data == 1);
	for(int i=2;i<10;++i){
		insert(i);
	}
	CU_ASSERT_EQUAL(list_size(get_head()),10);
	//test inserted at correct positions
	node_ptr node = get_head();
	for(int i =0; i<10;++i){
		CU_ASSERT_EQUAL(node->data, i);
		node = node->next;
	}
	CU_ASSERT_PTR_NULL(node);
	clear();
}

void inser_head_test(){
	for(int i =0; i< 10; ++i){
		insert_node_head(i);
	}
	CU_ASSERT_EQUAL(list_size(get_head()),10);
	node_ptr node = get_head();
	for(int i = 9; i>=0; --i){
		CU_ASSERT_EQUAL(node->data, i);
		node = node->next;
	}
	CU_ASSERT_PTR_NULL(node);
	clear();
}
