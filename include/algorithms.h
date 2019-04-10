#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "base.h"
/*
-----------------------------------------------
	merge sort algorithm
-----------------------------------------------
*/

/*
	@brief Method to perform merge sort
	@param arr: The array that we are concerned about sorting
	@param l: Where we will start sorting from
	@param r: This is where we stop sorting. Last items in the items we have to sort
	@param cmp: The comparator for the data item that we wiwll be sorting.
*/
void merge_sort(DATA *arr, int l, int r, DATA_COMPARE cmp);

/*
	@brief Method to merge the to halves of a list into one sorted list
	@param arr: The array that we are concerned about sorting
	@param l: Starting point of the first sub-list
	@param m: The ending of the first sub-list
	@param r: This is where we stop sorting. Last items in the items we have to sort
	@param cmp: The comparator for the data item that we wiwll be sorting.
*/
void merge(DATA *arr, int l, int m, int r, DATA_COMPARE cmp);

/*
	@brief: Method to copy one array from the other array
	@param arr: the array that we are copying from
	@param temp: the array that we are copying into arr
	@param size: the number of items we are copying.
*/
void arrcpy(DATA *arr, DATA *temp, int size);
#endif