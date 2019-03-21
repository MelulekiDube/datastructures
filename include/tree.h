#ifndef TREE_H
#define TREE_H

#include "base.h"
#include "queue.h" //this is for level-order printing

/*
*	@brief Typedef so that we have a common type for tree_node pointers	
*/
typedef struct binary_search_tree_node* bst_node_ptr;
/**
*	@brief Pointer to the tree type.
*/
typedef struct binary_search_tree* bs_tree;
/**tree_node:
* @brief This is the structure of the tree node. It contains:
*	data item that is stored on this current node.
*	left and right children of this node.
*/

typedef struct binary_search_tree_node{
	/*
		@brief The data item that is stored by the current node
	*/
	DATA data;
	/* 
		@brief These are the links to the left subtree and right subtree
	*/
	bst_node_ptr left, right;
}binary_search_tree_node;

/**binary_tree:
* @brief the actual tree type that will contain the root of this tree 
*/
typedef struct binary_search_tree{
	/**
		@brief the root of the tree
	*/
	bst_node_ptr root;
}binary_search_tree;

/*
	@brief This method will create a new tree and initialize its root to NULL
	@returns the new pointer to the new tree
*/
bs_tree create_bst(void);

/**********************************************************************************
						Tree basic functions
**********************************************************************************/
/** insert_bst:
*	@brief This method will insert the data item passed to the tree passed using the comparator passed. 
*	@param tree The tree we are coming to insert into
* 	@param data The data we are coming to insert into the tree.
*	@param comp the comparator function that we are going to using to determine where the data is going to stay in the tree
*/
void insert_bst(bs_tree tree, DATA data, DATA_COMPARE comp);

/**find:
*	@brief This function will using the comparator comp, search the tree for a node with data value equal to target. 
*	@param tree: The tree we are searching in
*	@param target: The data item we are looking for
	@param comp: The comparator that we are using to compare the data value to find the one equal to target
	@returns NULL if there is no such node and returns the a pointer to the node that has the data item equal to target
*/
bst_node_ptr find(bs_tree tree, DATA target, DATA_COMPARE comp);

/** delete_node
*	@brief Delete a node that has a data value target
*	@param tree: the tree we are deleting the node from.
*	@param target: The data we are looking to delete from the tree
*/
void delete_node(bs_tree tree, DATA target, DATA_COMPARE comp);

/**bst_height:
*	@brief This methods calculates the height of the tree.
	@param tree: The tree for which we are calculating the height for.
*/
int bst_height(bs_tree tree);

/**********************************************************************************
						Tree traversal functions
**********************************************************************************/

/**inorder:
*	@brief Performs inorder traversal of the tree. visit the left node the current and then the right tree.
*	@param tree 
*/
void inorder(bs_tree tree, DATA_ACTION print);

/**pre_order:
*	@brief Performs pre-order printing where we visit the current node before the children
*	@param tree: The tree that we will perform pre-order printing for
*/
void pre_order(bs_tree tree, DATA_ACTION print);

/**post_order:
*	@brief Performs post order printing where we visit the left then right nodes before vising the root node
*	@param tree: the tree we are going to perform post oder printing for.
*/
void post_order(bs_tree tree, DATA_ACTION print);

/**level_order:
*	@brief Performs level order printing for this particular tree
*	@param tree: The tree that we will perform the level-order printing for
*/
void level_order(bs_tree tree, DATA_ACTION print);

/**visit:
*	@brief This method will basic print what ever the data is at this node.
*	@param node: The node that we want to print
*	@param print: User defined print function for the data item
*/
void visit(bst_node_ptr node, DATA_ACTION print);

/*
	@brief This is a function that will clear and delete the tree instance from the heap.
*/
void delete_tree(bs_tree tree);
#endif