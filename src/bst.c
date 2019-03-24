#include <stdio.h>
#include "../include/tree.h"
#include <limits.h>
/****************************************************************************************
					forward declaration of private methods
****************************************************************************************/
void _insert_bst(bst_node_ptr r, DATA data, DATA_COMPARE comp);
bst_node_ptr _find(bst_node_ptr r, DATA target, DATA_COMPARE comp);
/****************************************************************************************
					Definitions of the methods.
****************************************************************************************/

/*
	@brief This method will create a new tree and initialize its root to NULL
	@returns the new pointer to the new tree
*/
bs_tree create_bst(void){
	bs_tree temp_tree = (bs_tree)malloc(sizeof(binary_search_tree));
	temp_tree->root = NULL;
	return temp_tree;
}

/**bst_nodeptr_creator:
*	@brief This is a private method to just create new memory and initialize the basic fields
	@param d The data to place in the new created node
	@returns The pointer to the created memory
*/
bst_node_ptr bst_nodeptr_creator(DATA d){
	bst_node_ptr temp = (bst_node_ptr)malloc(sizeof(binary_search_tree_node));
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}

/** insert_bst:
*	@brief This method will insert the data item passed to the tree passed using the comparator passed. 
*	@param tree The tree we are coming to insert into
* 	@param data The data we are coming to insert into the tree.
*	@param comp the comparator function that we are going to using to determine where the data is going to stay in the tree
*/
void insert_bst(bs_tree tree, DATA data, DATA_COMPARE comp){
	if(!tree->root){
		tree->root = bst_nodeptr_creator(data);
	}else{
		_insert_bst(tree->root, data, comp);
	}
}

/**_insert_bst:
*	@brief Private insert method which uses recursion to traverse through the tree to insert the new data in the correct location
*	@param r the root node for this subtree
*	@param data the data that we are coming to insert_bst
*	@param comp the comparator to use
*/
void _insert_bst(bst_node_ptr r, DATA data, DATA_COMPARE comp){
	int val  = comp(data, r->data);
	if(val<=0){
		if(r->left)
			_insert_bst(r->left, data, comp);
		else
			r->left = bst_nodeptr_creator(data);
	}else{
		if(r->right)
			_insert_bst(r->right, data, comp);
		else
			r->right = bst_nodeptr_creator(data);
	}
}

/**find:
*	@brief This function will using the comparator comp, search the tree for a node with data value equal to target. 
*	@param tree: The tree we are searching in
*	@param target: The data item we are looking for
	@param comp: The comparator that we are using to compare the data value to find the one equal to target
	@returns NULL if there is no such node and returns the a pointer to the node that has the data item equal to target
*/
bst_node_ptr find(bs_tree tree, DATA target, DATA_COMPARE comp){
	if(tree->root){
		return _find(tree->root, target, comp);
	}else{
		return NULL;
	}
}

/**
*	@brief Private function that helps the find function. Finds the node with data matching the target and returns that node
	@param r the root of this subtree
	@param target the target data we are looking for in the tree
	@param comp the user defined comparator function that we will to compare data
	@returns the node ptr having the same data as target
			returns null if no such node exists
*/
bst_node_ptr _find(bst_node_ptr r, DATA target, DATA_COMPARE comp){
	if(r){
		int val = comp(target, r->data);
		if(!val){
			return r;
		}else if(val<0){
			return _find(r->left, target, comp);
		}else{
			return _find(r->right, target, comp);
		}
	}
	return NULL;
}

/*
	@brief This is a function that will clear and delete the tree instance from the heap. 
*/
void delete_tree(bs_tree tree){
	void _delete_tree(bst_node_ptr r){
		if(r){
			_delete_tree(r->left);
			_delete_tree(r->right);
			free(r);
			r=NULL;
		}
	}
	_delete_tree(tree->root);
	free(tree);
}

/**max:
*	@brief Given two numbers will return the maximum number between the two numbers.
*	@param a the first number
*	@param b the second number.
*	@returns the maximum number between the two numbers and if they are equal that number is returned
*/
int max (int a, int b){
	return a>b?a:b;
}

/**bst_height:
*	@brief This methods calculates the height of the tree.
	@param tree: The tree for which we are calculating the height for.
*/
int bst_height(bs_tree tree){
		/**
	*	@brief Private Function that will calculate the height of the tree as a helper to the public function
	*	@param the node we are are currently calculating the height for
	*	@returns a number which is the height of the tree
	*/
	int _bst_height(bst_node_ptr r){
		if(!r)
			return 0;
		return 1+max(_bst_height(r->left), _bst_height(r->right));
	}
	return _bst_height(tree->root);
}

bst_node_ptr find_min(bst_node_ptr r){
	while(r&&r->left){
		r= r->left;
	}
	return r;
}

bst_node_ptr _delete_node(bst_node_ptr r, DATA target, DATA_COMPARE comp){
	if(!r)
		return r;
	int val = comp(target, r->data);
	if(val<0){
		r->left = _delete_node(r->left, target, comp);
		return r;
	}
	if(val>0){
		r->right = _delete_node(r->right, target, comp);
		return r;
	}
	//threee cases 1: node is leaf node, 2: has left or right 3 has both children
	//case1 leaf node
	if(!r->left &&!r->right){
		free(r);
		return NULL;
	}
	//case 2: node has left child only
	if(r->left&&!r->right){
		bst_node_ptr temp = r->left;
		free(r);
		return temp;
	}
	//case 2 second half
	if(r->right && !r->left){
		bst_node_ptr temp = r->right;
		free(r);
		return temp;
	}
	//case 3 node has 2 children
	bst_node_ptr min = find_min(r->right);
	min->left = r->left;
	free(r);
	return min;
}
/** delete_node
*	@brief Delete a node that has a data value target
*	@param tree: the tree we are deleting the node from.
*	@param target: The data we are looking to delete from the tree
*/
void delete_node(bs_tree tree, DATA target, DATA_COMPARE comp){
	tree->root = _delete_node(tree->root, target, comp);
}
/***********************************************************************************************
								Tree traversals
***********************************************************************************************/
/**inorder:
*	@brief Performs inorder traversal of the tree. visit the left node the current and then the right tree.
*	@param tree 
*/
void inorder(bs_tree tree, DATA_ACTION act){
	void _inorder(bst_node_ptr r){
		if(r){
			_inorder(r->left);
			act(r->data);
			_inorder(r->right);
		}
	}
	_inorder(tree->root);
}

/**pre_order:
*	@brief Performs pre-order printing where we visit the current node before the children
*	@param tree: The tree that we will perform pre-order printing for
*/
void pre_order(bs_tree tree, DATA_ACTION act){
	void _pre_order(bst_node_ptr r){
		if(r){
			act(r->data);
			_pre_order(r->left);
			_pre_order(r->right);
		}
	}
	_pre_order(tree->root);
}

/**post_order:
*	@brief Performs post order printing where we visit the left then right nodes before vising the root node
*	@param tree: the tree we are going to perform post oder printing for.
*/
void post_order(bs_tree tree, DATA_ACTION act){
	void _post_order(bst_node_ptr r){
		if(r){
			_post_order(r->left);
			_post_order(r->right);
			act(r->data);
		}
	}
	_post_order(tree->root);
}

/**level_order:
*	@brief Performs level order printing for this particular tree
*	@param tree: The tree that we will perform the level-order printing for
*/
void level_order(bs_tree tree, DATA_ACTION act){
	void _level_order(bst_node_ptr r){
		queue q = creat_queue();
		enque(q, ptr_val(r));
		while(!is_qempty(q)){
			bst_node_ptr n = (bst_node_ptr)deque(q).data_ptr;
			act(n->data);
			if(n->left)
				enque(q, ptr_val(n->left));
			if(n->right)
				enque(q, ptr_val(n->right));
		}
	}
	_level_order(tree->root);
}

void get_end_points(bst_node_ptr r, int d, int *min, int *max){
	if(r){
		if(d<*min)
			*min = d;
		if(d>*max)
			*max = d;
		get_end_points(r->left, d-1, min, max);
		get_end_points(r->right, d+1, min, max);
	}
}

void get_top_view(bst_node_ptr r, int d, int h, pair *p, int b){
	if(r){
		pair item = p[d+b];
		if(!item.val.data_ptr || h<item.key.data_int){
			p[d+b]=(pair){int_val(h), ptr_val(r)};
		}
		get_top_view(r->left, d-1, h+1, p, b);
		get_top_view(r->right, d+1, h+1, p, b);
	}
}

/**top_view
*	@brief This method will print the top view of a given tree. That is the nodes we can see from looking at the tree from above.
*	@param tree: the tree we want to print the top view for
*/
void top_view(bs_tree tree, DATA_ACTION act){
	int min=INT_MAX, max=INT_MIN;
	get_end_points(tree->root, 0, &min, &max );//get the end points for the tree
	int size = (max - min)+1;
	printf("\n\n size is: %d\n\n", size);
	pair combo[size];
	int base = 0-min;
	for(int i=0; i<size;++i){
		combo[i] = (pair){int_val(0), ptr_val(NULL)};
	}
	get_top_view(tree->root, 0, 0 ,combo, base);
	for(int i=0; i<size; ++i){
		bst_node_ptr temp = (bst_node_ptr)(combo[i].val.data_ptr);
		act(temp->data);
	}
}