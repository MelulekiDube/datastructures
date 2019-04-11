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
/*
-----------------------------------------------
	quick sort algorithm
-----------------------------------------------
*/
/*
	@brief: Method to do the partition for the quick sort algorithm
	@param arr: the array that we are sorting
	@param low: where we start sorting
	@param hi: we we stop sorting
*/
int partition(DATA *arr, int low, int hi, DATA_COMPARE cmp);
/*
	@brief: The quick sort function
	@param arr: the array that we are sorting
	@param low: where we start sorting
	@param hi: we we stop sorting
*/
void quick_sort(DATA *arr, int low, int hi, DATA_COMPARE cmp);

/*
	@brief: Method to swap two data items from an array
	@param d1: pointer to the first data items we are swapping
	@param d2: pointer to the second data item we are swapping
*/
void swap_data(DATA* d1, DATA* d2);

/*
------------------------------------------------
	searching algorithm
------------------------------------------------
*/
/**
	@brief Method to perform binary search in a sorted array arr
	@param arr: The array that we are searching through
	@param item: The item that we are looking for.
	@param size: The size of the array
	@param comp: The comparator for this DATA ITEM
*/
int binary_search(DATA *arr, int size, DATA item, DATA_COMPARE comp);
#endif