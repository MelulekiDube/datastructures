#include <stdlib.h>
#include <stdio.h>
#include "../include/tree.h"
#include "CUnit/Basic.h"


void test_bstcreate();
void insert_bsttest();
void find_bst_test();
void test_bst_height();
void test_delete();
void print_traversals();

char* args[] ={
	"Tree creation test",
	"Tree insert function test",
	"Tree find function test",
	"Tree get height function test",
	"Tree Deletion function",
	"Tree traversal functions"
};

void (*bst_test[])() = {
	&test_bstcreate,
	&insert_bsttest,
	&find_bst_test,
	&test_bst_height,
	&test_delete,
	&print_traversals
};
extern int compare(DATA d1, DATA d2);
int vals [] = {13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};

int test_bst(void){
	 // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_pSuite basic_operations_suit = NULL;
	// Add a suite to the registry
	basic_operations_suit = CU_add_suite("Testing tree Operations", 0, 0);
	// Always check if add was successful
	if (!(basic_operations_suit)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	for(int i=0; i<6;++i){
		if (!CU_add_test(basic_operations_suit, args[i], *bst_test[i])) {
		  CU_cleanup_registry();
		  return CU_get_error();
		}
	}
	 // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}

void test_bstcreate(){
	bs_tree tree = create_bst();
	CU_ASSERT_PTR_NOT_NULL(tree);
	CU_ASSERT_PTR_NULL(tree->root);
	delete_tree(tree);
}
void insert_bsttest(){
	bs_tree tree = create_bst();
	insert_bst(tree, int_val(4), &compare);
	CU_ASSERT_EQUAL(tree->root->data.data_int, 4);
	CU_ASSERT_PTR_NULL(tree->root->left);
	CU_ASSERT_PTR_NULL(tree->root->right);
	insert_bst(tree, int_val(2), &compare);
	CU_ASSERT_PTR_NOT_NULL(tree->root->left);
	CU_ASSERT_PTR_NULL(tree->root->right);
	CU_ASSERT_EQUAL(tree->root->left->data.data_int, 2);
	insert_bst(tree, int_val(5), &compare);
	CU_ASSERT_PTR_NOT_NULL(tree->root->right);
	CU_ASSERT_EQUAL(tree->root->right->data.data_int, 5);
	delete_tree(tree);
}

void test_insert(bs_tree tree){
	for(int i=0; i< 15; ++i){
		insert_bst(tree, int_val(vals[i]), &compare);
	}
}

void find_bst_test(){
	bs_tree tree = create_bst();
	test_insert(tree);
	bst_node_ptr  temp = tree->root->left->right->right;
	CU_ASSERT_EQUAL(temp, find(tree,int_val(12),&compare));
	CU_ASSERT_PTR_NULL(find(tree,  int_val(0), &compare));
	delete_tree(tree);
}

void test_bst_height(){
	bs_tree tree = create_bst();
	CU_ASSERT_EQUAL(bst_height(tree), 0);
	test_insert(tree);
	CU_ASSERT_EQUAL(bst_height(tree), 9);
	delete_tree(tree);
}

void print_data(DATA d){
	printf("%lld, ", d.data_int);
}

void print_traversals(){
	bs_tree tree = create_bst();
	test_insert(tree);
	printf("\nInorder Traversal:\n");
	inorder(tree, &print_data);
	printf("\nPreOrder traversal:\n");
	pre_order(tree, &print_data);
	printf("\nPostOrder traversal:\n");
	post_order(tree, &print_data);
	printf("\nLevelOrder traversal:\n");
	level_order(tree, &print_data);
	printf("\nTop view:\n\n");
	top_view(tree, &print_data);
}

void test_delete(){
	bs_tree tree = create_bst();
	test_insert(tree);
	delete_node(tree, int_val(7), &compare);
	CU_ASSERT_EQUAL(bst_height(tree), 8);
	printf("\n\nAfter deleting 7 from the tree is as below\nLevelOrder traversal:\n");
	level_order(tree, &print_data);
	delete_node(tree, int_val(1), &compare);
	printf("\n\nAfter deleting 1 from the tree is as below\nLevelOrder traversal:\n\n");
	level_order(tree, &print_data);
	delete_node(tree, int_val(13), &compare);
	printf("\n\nAfter deleting the 13 from the tree is as below\nLevelOrder traversal:\n\n");
	level_order(tree, &print_data);
	delete_tree(tree);
	printf("\n\n\n");
}