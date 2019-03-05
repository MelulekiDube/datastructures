/*
	This is just a small file to learn more about CUnit so that we can do unit testing for the 
	Data structures
	
	Code written was taken ferom 	https://medium.com/@marinalimeira/tdd-using-cunit-first-steps-5c4c2a8655e6
	
	



**/

#include "CUnit/Basic.h"
#include "sum.c"

void sum_test() {
  // Check if first param matches with second[2]
  CU_ASSERT_EQUAL(sum(2, 14), 16);
  CU_ASSERT_EQUAL(sum(0, 0), 0);
  CU_ASSERT_EQUAL(sum(-1 ,6), 5);
}

int main() {
   // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_pSuite pSuite = NULL;
	// Add a suite to the registry
	pSuite = CU_add_suite("sum_test_suite", 0, 0);
	// Always check if add was successful
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "sum_test", sum_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}

