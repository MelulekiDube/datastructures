#ifndef BASE_H
#define BASE_H


/*****************************************************************************************************************
				The basic data object
This whole idea was inspired by Stephen https://github.com/brenns10/libstephen and from  https://github.com/kammitama5/Data-Structures-And-Algorithms-Hacktoberfest18
The alternative to this was to have a data object with void pointer only and after reading about Unions and other peoples implementations I then settled on going with this approach.
******************************************************************************************************************/
/*
	Union for the basic data that will be used. we can either store an long long int or double or a pointer
	This idea was inspired by Stephen
*/
typedef union DATA {
  long long int data_int; //ensure that its 8bytes
  double data_dbl;  //double is also 8 bytes
  void * data_ptr; //pointer can be cast to a more wanted pointer
} DATA;


/*
	@brief user defined function that will compare two data items together. This function is used for equality checking when deleting items. And will also be used for ordering purposes like sorting the list.
	@returns If the first data item is less than the second we return a value less than 1 and if they are equal we return a value of 0 otherwise we return a value greater than 1.
*/
typedef int (*DATA_COMPARE)(DATA, DATA);


/*
	@brief User defined function that will print the data object
	@param Data item to print
*/

typedef void (*DATA_ACTION)(DATA);

#define int_val(value) ((DATA){.data_int=value})
#define dbl_val(value) ((DATA){.data_dbl=value})
#define ptr_val(value) ((DATA){.data_ptr = value})

typedef struct pair{
	DATA key;
	DATA val;
}pair;
#endif
