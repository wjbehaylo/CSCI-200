/* CSCI 200: LAB 3 C: L3C Array Test Suite
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // went to office hours for help with failing test 49, made a return in remove element so that if size was 0 or pArray was null it quit
 * create a variety of functions to work with arrays and pass the tests in the test suite
 */

#include "array_functions.h"
#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

void array_allocate(int*& pArray, const int INIT_SIZE){
    pArray = new int[INIT_SIZE]; // this makes a pointer to a new array of the initial size
    for (int i = 0; i<INIT_SIZE; i++){
        pArray[i] = 0;
    }
}

int array_get_element_at(const int* pArray, const int SIZE, const int POS){
   if (pArray == nullptr){ //this throws an exception if pArray is a null pointer
        throw out_of_range("pArray is a nullpointer");
    }
    
    if (POS >= 0 && POS<SIZE){
        int element = pArray[POS];
        return element;
    }
    else {throw out_of_range("invalid access");} // throws out_of_range if we try to access elements of array that aren't allocated to it
    
    }

void array_set_element_at(int*& pArray, const int SIZE, const int POS, const int VALUE){
    if (POS >= 0 && POS<SIZE && pArray != nullptr){
        pArray[POS] = VALUE;
        return;
    }
    return;
}

void array_deallocate(int*& pArray, int& size){ // for the pArray we need to pass the pointer by reference because we are making a change to it, not just to where it points
    delete[] pArray;
    pArray = nullptr;
    size = 0;
}

void array_insert_at_position(int*& pArray, int& size, const int POS, const int VALUE){
    size++;
    int* new_array = new int[size];
    if(POS<=0){
        new_array[0] = VALUE; // if its before, we make the first element the new value, and then copy over the rest of the original array
    for (int i = 1; i< size; i++){
        new_array[i] = pArray[i-1];
    }
}
    else if (POS >= size-1) // if the position is greater than or equal to what the size initially was
    {
        new_array[size-1] = VALUE; // the last element of the new array will be the value
        for (int i = 0; i<size-1; i++){ //going from 0 to the old size,
            new_array[i] = pArray[i];  //each position of new array will be what the same position fo old array held
        }
    }
    else {
        for (int i = 0; i<POS; i++){
            new_array[i] = pArray[i];
        }
        new_array[POS] = VALUE;
        for (int i = POS +1; i<size; i++){
            new_array[i] =  pArray[i-1];
        }
    }
    delete[] pArray;
    pArray = nullptr;
    pArray = new_array; //makes pArray a pointer to the new, larger, inserted array
    new_array = nullptr; // prevent dangling pointer
    return;
}

int array_min(const int* pArray, const int SIZE){
    if (SIZE == 0){
        throw out_of_range("Empty Array");
    }
    if (pArray == nullptr){
        throw out_of_range("pArray is a nullptr");
    } 

    int min = pArray[0];
    for (int i = 1; i<SIZE; i++){
        if (min> pArray[i]) {
            min = pArray[i];}
    }

return min;
}

int array_max(const int* pArray, const int SIZE){
    if (SIZE == 0) throw out_of_range("Empty Array");
    if (pArray == nullptr) throw out_of_range("pArray is a nullptr");

    int max = pArray[0];
    for (int i = 1; i<SIZE; i++){
        if (pArray[i] > max) {
            max = pArray[i];}
    }
    return max;
}

int array_find(const int* pArray, const int SIZE, const int TARGET){

    for (int i = 0; i<SIZE; i++){ //going through each element
        if (pArray[i] == TARGET){ //if the element is the target...
            return i; //we return the index it was found at
        }
    }
    //if we go through and don't return any i, it means we didn't find the target
    return -1;
}

void array_remove_from_position(int*& pArray, int&size, const int POS){
    if (size == 0 || pArray == nullptr){ //if there is no size of the array it can't be shrunk, if pArray isn't pointing the rest of the function won't work
        return;
    }
    size --;
    int* new_array = new int[size];
    if (POS <= 0){ // if we are trying to remove and element < range
        for (int i = 0; i<size; i++){
            new_array[i] = pArray[i+1]; //we remove the first element by copying all the values from pArray that are after the first element
        }
    }
    else if (POS > size){ // if we are trying to remove an element > range
        for (int i = 0; i<size; i++){
            new_array[i] = pArray[i]; //we just go through all the elements of pArray until the last
        }
    }
    else { // if we are trying to remove an element within the range, we copy pArray into new_array until we get to that element, then skip copying it into new_array
        for (int i = 0; i<POS; i++){
            new_array[i] = pArray[i];
        }
        for (int i = POS; i<size; i++){
            new_array[i] = pArray[i+1];
        }
    }
    delete []pArray;
    pArray = new_array; //makes pArray a pointer to new_array
    return;
}