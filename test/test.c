#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"
#include "CUnit/Basic.h"

void insert_test();

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
   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}

void insert_test(){
	//assert the head is originally null
	CU_ASSERT_PTR_NULL(get_head());
	insert(0);
	CU_ASSERT_PTR_NOT_NULL(get_head());
}