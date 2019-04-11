#include <stdio.h>
#include "../include/algorithms.h"
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
void merge_sort(DATA *arr, int l, int r, DATA_COMPARE cmp){
	if(r>l){
		int m = (l+r)/2; 	//divide the array into to
		//call merge_sort() on the two halves
		merge_sort(arr, l, m, cmp); 
		merge_sort(arr, m+1, r, cmp);
		//merge the two halves
		merge(arr, l, m, r, cmp);
	}
}

/*
	@brief Method to merge the to halves of a list into one sorted list
	@param arr: The array that we are concerned about sorting
	@param l: Starting point of the first sub-list
	@param m: The ending of the first sub-list
	@param r: This is where we stop sorting. Last items in the items we have to sort
	@param cmp: The comparator for the data item that we wiwll be sorting.
*/
void merge(DATA *arr, int l, int m, int r, DATA_COMPARE cmp){
	int left_index, right_index, size, index;
	left_index = l;
	right_index  = m+1;
	size = (r-l)+1;
	index = 0;
	DATA temp[size];
	while(left_index<= m && right_index <= r){
		int cond = cmp(arr[left_index], arr[right_index]);
		if(cond <= 0)
			temp[index++] = arr[left_index++];
		else
			temp[index++] = arr[right_index++];
	}
	arrcpy(&temp[index], &arr[left_index], (m+1)-left_index);
	arrcpy(&temp[index], &arr[right_index], r+1-right_index);
	arrcpy(&arr[l], temp, r-l+1);
}	

/*
	@brief: Method to copy one array from the other array
	@param arr: the array that we are copying from
	@param temp: the array that we are copying into arr
	@param size: the number of items we are copying.
*/
void arrcpy(DATA *arr, DATA *temp, int size){
	while(size-->0){
		//printf("copying %d ", temp->data_int);
		*arr++ = *temp++;
		//printf("arr now %d \n", arr->data_int);
		//arr;
	}
}
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
int partition(DATA *arr, int low, int hi, DATA_COMPARE cmp){
	
	DATA pivot = arr[low]; //set the value of the pivot
	int i = low-1; //index the smallest element
	for(int j=low+1; j <= hi; ++j){
		
		int cond = cmp(arr[j], pivot);//check if item j is smaller than the pivot
		if(cond<=0){
			swap_data(&arr[++i], &arr[j]);//swap item j with the element next to the smallest item
		}
	}
	swap_data(&arr[i], &arr[low]); //place j on the right track
	return ++i; //return the index of the pivot
}

/*
	@brief: Method to swap two data items from an array
	@param arr: array containing the items that we want to swap
	@param index_d1: index of the first data items we are swapping
	@param index_d2: index of the second data item we are swapping
*/
void swap_data(DATA* d1, DATA* d2){
	DATA temp = *d1;
	*d1 = *d2;
	*d2 =  temp;
}

/*
	@brief: The quick sort function
	@param arr: the array that we are sorting
	@param low: where we start sorting
	@param hi: we we stop sorting
*/
void quick_sort(DATA *arr, int low, int hi, DATA_COMPARE cmp){
	if(hi > low){
		int pi = partition(arr, low, hi, cmp);
		quick_sort(arr, low, pi-1,cmp);
		quick_sort(arr, pi+1, hi, cmp);
	}
}
