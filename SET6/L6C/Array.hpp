//This is where the array class extension is made

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "List.hpp" //necessary for inheritance

using namespace std;

template <typename T>
class Array: public List<T>{
    public:
    T get(const int POS) const override{
        if(POS >= 0 && POS< List<T>::mSize && List<T>::mSize !=0) { //makes sure we are getting a value in the range, by checking POS against bounds of array and making sure Array isn't empty
            return pArray[POS];
        }
        return -1;
    }
    void set(const int POS, const T VALUE) override{
        if (List<T>::mSize>0 && POS >= 0 && POS< List<T>::mSize){ //only do stuff if the array exists, and if we are setting a value within the array
            pArray[POS] = VALUE;
            return;
        }
        return;
    }
    void insert(const int POS, const T VALUE) override{
        //if our array is empty (mSize == 0), we need to allocate a new one and set pHead pointing to the front
        List<T>::mSize++; //increase size because we are inserting
        T* new_array = new T[List<T>::mSize];

        if (List<T>::mSize ==1){ //if the array had been empty, we need only make a 1 element array
            new_array[0] = VALUE; //we make the first value of the new array the value
            delete[] pArray; //we get rid of the old array to avoid memory leaks
            pArray = new_array; //we make the old array's head point to the new array
            return; //now we are finished
        }
        //now that the case of an empty array has been handled, we can move on to non-empty arrays
        
        //if the position was less than or equal to 0, we make the first element the element to insert and add the old array to the back of the new array
        if(POS<=0){
            new_array[0] = VALUE; // if its before, we make the first element the new value, and then copy over the rest of the original array
            for (int i = 1; i< List<T>::mSize; i++){
                new_array[i] = pArray[i-1];
            }
        }
        else if( POS>= List<T>::mSize-1){ //if we are working with a position after the end of the array
            for(int i = 0; i<List<T>::mSize-1; i++){
                new_array[i] = pArray[i];
            }
            new_array[List<T>::mSize-1] = VALUE; //makes last value of array the input value
        }
        else { //otherwise the position must be within the array
            for(int i = 0; i<POS; i++){ //copy through the array until we get to the position
                new_array[i] = pArray[i];
            }
            new_array[POS] = VALUE; // make the value at the position the target value

            //now we need to finish building the array
            for (int i = POS+1; i<List<T>::mSize; i++){
                new_array[i] = pArray[i-1];
            }
        }

        //now the new array has been made, we can delete the old array and make the pointer point to the new array
        delete[] pArray;
        pArray = new_array;
        return;
        }

    void remove(const int POS) override{
        if (List<T>::mSize == 0 || pArray == nullptr){ //if there is no size of the array it can't be shrunk, if pArray isn't pointing the rest of the function won't work
        return;
    }
    List<T>::mSize --;
    T* new_array = new T[List<T>::mSize];
    if (POS <= 0){ // if we are trying to remove and element < range
        for (int i = 0; i<List<T>::mSize; i++){
            new_array[i] = pArray[i+1]; //we remove the first element by copying all the values from pArray that are after the first element
        }
    }
    else if (POS > List<T>::mSize){ // if we are trying to remove an element > range
        for (int i = 0; i<List<T>::mSize; i++){
            new_array[i] = pArray[i]; //we just go through all the elements of pArray until the last
        }
    }
    else { // if we are trying to remove an element within the range, we copy pArray into new_array until we get to that element, then skip copying it into new_array
        for (int i = 0; i<POS; i++){
            new_array[i] = pArray[i];
        }
        for (int i = POS; i<List<T>::mSize; i++){
            new_array[i] = pArray[i+1];
        }
    }
    delete [] pArray; //avoid memory leaks by deallocating before changing pointer
    pArray = new_array; //makes pArray a pointer to new_array
    return;
}

    private: 
    T* pArray; //a pointer to the  array?


};

#endif