#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Allocates an integer array of a target size on the free store.
 * Upon function return, pArray will point to starting address and the 
 * contents of pArray will all be initalized to zero.
 * 
 * @param pArray pointer to integer array
 * @param INIT_SIZE initial array size as an integer
 * 
 * @note Runtime of function O(n), because to make the pointer point its O(1), but to initialize the contents it is O(n)
 */
void array_allocate(int*& pArray, const int INIT_SIZE);

/**
 * @brief Returns the value of the element at a target position.  If the
 * position it not within the array size, throws a standard exception
 * 
 * @param pArray pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to retrieve value from
 * @return int element value at given position
 * @throws standard exception if array is null or position out of range
 * 
 * @note Runtime of function O(1), because it is accessing a single element with a known memory address (pArray + POS)
 */
int array_get_element_at(const int* pArray, const int SIZE, const int POS);

/**
 * @brief Sets the value of the element at a target position.  If the
 * position is out of range, does nothing.
 * 
 * @param pArray pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to set value at
 * @param VALUE value to place at target position
 * 
 * @note Runtime of function O(1), accessing a single element and changing it only requires looking at one address
 */
void array_set_element_at(int*& pArray, const int SIZE, const int POS, const int VALUE);

/**
 * @brief Deallocates an integer array, returning its memory back to
 * the free store.  Upon function return, pArray will be set to be a
 * null pointer and the array size will be set to zero.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * 
 * @note Runtime of function O(size), because the delete[] keyword deletes the value of each element in the array, meaning it has to parse through the array
 */
void array_deallocate(int*& pArray, int& size);

/**
 * @brief Inserts a value at a target position.  If the position is
 * out of range, inserts at the front/back as appropriate.  Upon
 * function return, the array will be increased in size by one.  The
 * array size will be updated to the new size.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to insert value at
 * @param VALUE value to insert at target position
 * 
 * @note Runtime of function O(n), O(n) because we are growing the array so we have to parse through each element, and copy it to a new array
 */
void array_insert_at_position(int*& pArray, int& size, const int POS, const int VALUE);

/**
 * @brief Returns the minimum value within the array.  If array size is
 * zero or the array is uninitialized, throws a standard exception.
 * 
 * @param pArray pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int minimum value within the array
 * @throws standard exception if array is null or position out of range
 * 
 * @note Runtime of function O(n), because we need to iterate through each element of the array
 */
int array_min(const int* pArray, const int SIZE);

/**
 * @brief Returns the maximum value within the array.  If array size is
 * zero or the array is uninitialized, throws a standard exception.
 * 
 * @param pArray pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int maximum value within the array
 * @throws standard exception if array is null or position out of range
 * 
 * @note Runtime of function O(n), it iterates through each element of the array
 */
int array_max(const int* pArray, const int SIZE);

/**
 * @brief Returns the first position within an array a target value 
 * is located at.  If the target value is not present within the 
 * array, returns -1.
 * 
 * @param pArray pointer to the integer array (the haystack)
 * @param SIZE size of the array as an integer
 * @param TARGET target integer value to search for in the array (the needle)
 * @return int position within the array target value is located (or -1 if not present)
 * 
 * @note Runtime of function O(n), we need to iterate every element until we find the value
 */
int array_find(const int* pArray, const int SIZE, const int TARGET);

/**
 * @brief Removes a value at a target position.  If the position is
 * out of range, removes from the front/back as appropriate.  Upon
 * function return, the array will be decreased in size by one.  The
 * array size will be updated to the new size.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to remove value from
 * 
 * @note Runtime of function O(n), we need to go through each element and copy it to another array
 */
void array_remove_from_position(int*& pArray, int& size, const int POS);

#endif
