#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"
#include <iostream>
#include <exception>
using namespace std;


class LinkedList {
    private: 

    /**
    * @brief a pointer to the first node in the linked list
    */
    Node* mpHead;

    /**
    * @brief a pointer to the last node in the linked list
    */
    Node* mpTail;


    /**
    * @brief an integer representing the number of nodes in the list
    */
    unsigned int mSize; 
    
    /**
    * @brief makes a node of given value, with null pointers for pNext and pPrev
    * @param VALUE the integer value to be stored in the node
    * @return Node* pointer to the newly created node
    */ 
    Node* mMakeNodeForValue(const int VALUE);

    public:
    /**
    * @brief a constructor for the linked list, initializes size to 0, and pTail and pHead to be nullptrs
    */
    LinkedList();

    /**
    * @brief a destructor for the linked list, sets the size of the list to 0 and deallocates each node
    */
    ~LinkedList();

    /**
    * @brief gets the value of the node at a given position in the list
    * @param POS the position the value should be gotten from
    * @return returns the value of the element at given position, 
    * @throws out_of_range if the position is not a position in the list
    */
    int get(const int POS);

    /**
    * @brief finds the first occurance of a value in the list
    * @param TARGET the target value that will be searched for in the list
    * @return returns the index of the position where the TARGEt was found if found, otherwise returns -1
    */
    int find(const int TARGET);

    /**
    * @brief inserts a node into the list, at the beginning or end if the specified POS is before or after the list, respectively
    * @param POS the position that the node will be inserted into
    * @param VALUE the value of the node that will be inserted
    */
    void insert(const int POS, const int VALUE);

    /**
    * @brief finds the maximum value within a linked list
    * @return the maximum value of the list
    * @throws out_of_range if the list is empty
    */
    int max();
    /** 
    * @brief finds the minimum value within a linked list
    * @return the minimum value of the list
    * @throws out_of_range if the list is empty
    */
    int min();

    /**
    * @brief if the provided position is in the list, remove it, deallocate it, and shrink the list size, if it is out of the range of the list, get rid of the first or last node
    * @param POS the position where the node will be removed
    */
    void remove(const int POS);

    /**
    * @brief if the provided position exists in the list, set the value of it, otherwise, do nothing
    * @param POS the position that will have its value changed (if it exists)
    * @param VALUE the value that the position will be changed to
    */
   
    void set(const int POS, const int VALUE);

    /**
    * @brief gets and returns the current size of the list
    * @return returns the size of the list, stored above in mSize
    */
    unsigned int size();

};
#endif