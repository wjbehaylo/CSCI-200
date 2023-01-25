#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <vector>
#include "LinkedList.hpp"
using namespace std;


/**
* @brief this function prints out the contents of a vector
* @param list this is the vector that is having its contents printed
* @return void, because the printing happens during
*/
template <typename T>
void print(LinkedList<T> list){
    for (int i = 0; i<list.size(); i++){
        cout<< list.get(i)<<" ";
    }
    cout<< endl;
}

/**
* @brief this is the merge function, which combines two sorted lists together, sorting them in the process
* @param half_1 this is the first list that will be combined
* @param half_2 this is the second list that will be combined
* @return returns a sorted list
*/
template<typename T>
LinkedList<T>* merge(LinkedList<T>* half_1, LinkedList<T>* half_2){
    LinkedList<T>* combination = new LinkedList<T>;
    //this variable is to record how far apart our two different vectors are, with positive meaning ahead on 1, negative ahead on 2
    int i = 0, j = 0;
    while (combination->size() < (half_1->size() + half_2->size())){
        if(half_1->get(i) < half_2->get(j)){
            combination->insert(combination->size(), half_1->get(i));
            i++;
        }
        else if (half_1->get(i) >= half_2->get(j)){
            combination->insert(combination->size(),half_2->get(j));
            j++;
        }
        if (i == half_1->size()){ // if we are past the last element of i, we just need to add the remaining elements of j
            while (j <half_2->size()){
                combination->insert(combination->size(), half_2->get(j));
                j++;
            }
        }
        if (j == half_2->size()){ // same thing applies for this scenario
            while (i< half_1->size()){
                combination->insert(combination->size(),half_1->get(i));
                i++;
            }
        }
    }
    // now we just need to get rid of the vectors, we do this by emptying their memory and then shrinking their capacity down to number of elements
    delete half_1;
    delete half_2;
    return combination;
        }


/**
* @brief this function will use the above merge function and order any list from lowest to highest value
* @param input this is the initial vector that will be sorted
* @return no return value because the input is passed by reference
**/
    template<typename T>
    void mergesort(LinkedList<T>*& input){
        
        //first we have to see if the input's size is greater than one, in which case we should split it in 2
        if (input->size() <= 1) return;
        
        LinkedList<T>* half_1 = new LinkedList<T>;
        LinkedList<T>* half_2 = new LinkedList<T>;
            //this function splits the input list into two halves
            for (int i = 0; i<(input->size()/2); i++){
                half_1->insert(half_1->size(), input->get(i));
                half_2->insert(half_2->size(), input->get(i+(input->size()/2)));
            }
            if (input->size()%2 == 1){ //if there are an odd number of inputs, we need to add the last one to half2, otherwise it will be forgotten
                half_2->insert(half_2->size(),input->get(input->size()-1));
            }
        mergesort(half_1);
        mergesort(half_2);
        //now they should both be sorted, so we can use the merge function to recombine them.
        input = merge(half_1, half_2);
        return;
    }

    #endif