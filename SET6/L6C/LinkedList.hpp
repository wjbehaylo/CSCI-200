#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

//this is our file for the concrete linked list
#include "List.hpp"
#include "Node.hpp"

template<typename T>
class LinkedList: public List<T>{
    private: 

    /**
    * @brief a pointer to the first node in the linked list
    */
    Node<T>* mpHead;

    /**
    * @brief a pointer to the last node in the linked list
    */
    Node<T>* mpTail;

    /**
    * @brief makes a node of given value, with null pointers for pNext and pPrev
    * @param VALUE the  value to be stored in the node
    * @return Node* pointer to the newly created node
    */ 
    Node<T>* mMakeNodeForValue(const T VALUE){
        Node<T>* new_node = new Node<T>;
        new_node->value = VALUE;
        new_node->pPrev = nullptr;
        new_node->pNext = nullptr;
        return new_node;
    }

    public:
    T get(const int POS) const override{
        Node<T>* curr_node = mpHead;
        if (curr_node == nullptr || List<T>::mSize == 0) {return -1;}
            int counter = 0;
    
            while (curr_node != nullptr){
                if (counter == POS) return curr_node ->value;
                counter ++;
                curr_node = curr_node ->pNext;
            }
        return -1; //if we get to this point without finding the position, it is not in the list
    }
    
    void set(const int POS, const T VALUE) override{

    if (POS < 0 || POS > List<T>::mSize -1 || List<T>::mSize == 0) return; //if the position is not in the list or the list is empty, the function does nothing
    Node<T>* curr_node = mpHead;
    int counter = 0;
    while (curr_node != nullptr){ // if the list is empty, or we are at the end of it and haven't found the position, we end the function
        if (POS == counter){ // if the current position is what we are looking for, 
            curr_node -> value = VALUE; //make the value of the current node equal to VALUE
            return; // then we are done
        }
        //otherwise,
        counter ++; //incriment the counter,
        curr_node = curr_node ->pNext; //move curr_node to point to the next node
    }
    }
    void insert(const int POS, const T VALUE) override{
        List<T>::mSize ++; //we are adding a value so the list's size increases
    Node<T>* curr_node = mpHead;
    Node<T>* insert_node = mMakeNodeForValue(VALUE); //here we make the new node to be inserted
    if(curr_node == nullptr){// if the list is empty, it will now contain the new node
        mpHead = insert_node; 
        mpTail = insert_node;
        return;
    }

    if (POS <= 0){ //if we are inserting a value at or before the list begins
        insert_node->pNext = mpHead; //make the new node point to the former head
        mpHead->pPrev = insert_node; //make the former head point to the new node
        mpHead = insert_node; //now make the new node the new head.
        return;
    }

    if (POS >= List<T>::mSize-1){ //if we are aiming to insert as the last element
        insert_node ->pPrev = mpTail; // previous of new tail is old tail
        mpTail ->pNext = insert_node; //next of old tail is new tail
        mpTail = insert_node; //new tail is set
        return;
    }
    int counter = 0;
    while (curr_node != nullptr){
        if (POS == counter){
            // if we are at the spot
            // we need to make the previous node point to the new node and the new node point to the previous node
            curr_node->pPrev->pNext = insert_node; // previous node points to inserted node
            insert_node->pPrev = curr_node->pPrev; // inserted node points to previous node

            //we also need to make the current node point back to the new node and the new node point to the current node
            curr_node ->pPrev = insert_node;
            insert_node->pNext = curr_node;
            return;
        }
        //otherwise
        counter ++; //incriment the counter
        curr_node = curr_node->pNext; //move on to the next node
    }
    //if we've gotten to this point without exiting, that means that the node must not be within the size of the list, so we add it to the back
    
}

    void remove(const int POS) override{
        if (List<T>::mSize ==0){ //if the list is empty, we quit the function
            return;
        }
        List<T>::mSize--; //otherwise, we will be removing a value so the size shrinks
        if (mpHead == mpTail) {// if the list only has one element, we will remove and deallocate that one element
            delete mpHead;
            mpHead = nullptr;
            mpTail = nullptr;
            return;
        
        }

        Node<T>* curr_node = mpHead; //this is the node we will use for storing nodes

        if( POS <= 0){ //if we are removing at or before the first value, we just remove mpHead
            mpHead->pNext->pPrev = nullptr; //the one after the first node now has nothing before it
            curr_node = mpHead->pNext; //we need to store the next node so we know what the new mpHead will be
            delete mpHead; //deallocate the old head
            mpHead = curr_node; //make mpHead point to the node that used to be after it
            return; //function is over
        }
        else if( POS>= List<T>::mSize){ //if we are trying to remove an element at or past the end of the list, we remove the last element (mpTail)
            curr_node = mpTail;
            mpTail->pPrev->pNext = nullptr; //now the second to last node points to nothing after it
            delete mpTail; //deallocate the old tail
            mpTail = curr_node; //make mpTail point to the node before what it used to point to
            return;
        }
        else { //at this point we know that the position is within the list
            int counter = 0;
            //if we've gotten to this point then the removed node must be between the second and second to last elements of the list
            while(true){ 
                if (counter == POS){ // if we are at the position to be removed,
                    curr_node ->pPrev ->pNext = curr_node ->pNext; // the previous nodes points to the next node
                    curr_node ->pNext ->pPrev = curr_node ->pPrev; // the next node points back to the previous node
                    delete curr_node; //de allocate the memory being used for the now deleted node
                    return; // after the node is deleted, the function is done
                }
                //other wise move to the next node
                counter ++; //increase counter,
                curr_node = curr_node ->pNext; //move curr_node to point to whatever the next node in the list is.
            }
        }

    }
};

#endif
