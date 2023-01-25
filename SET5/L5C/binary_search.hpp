#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <iostream>
#include <vector>
#include "LinkedList.hpp"
using namespace std;


/**
* @brief this function recursively performs a binary search on an input vector
* @param vect this is the vector that will be searched
* @param value this is the value being searched for
* @return returns the integer position, returning -1 if the value is not present
*/
template <typename T>
int binary_search(LinkedList<T>* list, T value){
    //to do a binary search iteratively, we must make a bunch of sublists of our initial list, going until the size of the list is one
    list->print();
    LinkedList<T> sublist = *list; //make sublist be a deep copy of our current list, so that we can edit it without changing the actual list
    //for the position we can't exactly just find it at different points, so we will need to change it during the loop
    int position = list->size()/2; //initialize the position to be the first element thats gonna be checked
    int size;
    sublist.print();
    while(sublist.size() >= 1){
        //make size for this loop
        size = sublist.size();
        //if we have found the value
        if (sublist.get(sublist.size()/2) == value){
            int i = 1;
            while((sublist.size()/2) -i >=0){
                if (sublist.get(sublist.size()/2 -i) == value){
                // this is where we make sure we get the earliest occurance
                position --; //move to previous position
                i++;
                }
                else break;
            }
            return position; // if the element in the middle of the current list is the target value, return the position currently being checked
        }
        
        else if (sublist.get(sublist.size()/2) < value){
        //if the value is less than the current value, make sublist be the right half of the current list
        for(int i = 0; i<size/2; i++){
            sublist.remove(0); //we remove the first element once for each element we aren't considering anymore
        }
        // update position, by adding half the size of the new list to it
        position += sublist.size()/2 +sublist.size()%2; 
        }
        else if (sublist.get(sublist.size()/2) > value){
        // if the value is greater than the current value, make sublist the left half of the current list
        for(int i = size/2; i<size; i++){ //here we remove everything at and after the midpoint from the list
            sublist.remove(sublist.size()); //we remove the last element once for each element we aren't considering anymore
        }
        // now we need to update position, by subtracting from it half the size of this new list, size we will be checking that value next
        position -= sublist.size()/2 +sublist.size()%2;
        }
    }
    delete &sublist;
    return -1; // if we go through all binary search options and don't find it, we return -1
}

#endif