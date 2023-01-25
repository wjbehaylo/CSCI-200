/* CSCI 200: LAB 4 A: L4A linked list functions
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // none
 * create a variety of functions to work with linked lists and pass the test suite
 */

#include "linked_list_functions.h"

#include <exception>
#include <iostream>
#include <string>
using namespace std;

Node* linked_list_make_node(const int VALUE) {
    Node* pNode = new Node;
    pNode->value = VALUE;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

void linked_list_add_value_to_front(Node*& pHead, Node*& pTail, const int VALUE) {
    // make a new node
    Node* pNewNode = linked_list_make_node(VALUE);      
    // if list is initially empty
    if (pHead == nullptr && pTail == nullptr){ //if neither the head nor tail are initialized
        // head and tail are the new node 
        pHead = pNewNode; //setting a pointer to a pointer
        pTail = pNewNode; //setting a pointer to a pointer
    }
    else {
    // otherwise, chain into existing node
        pHead->pPrev = pNewNode; //makes the previous pHead's pPrev point to the new pHead
        pNewNode->pNext = pHead; // makes pNext of the new Node point to the previous pHead
        pHead = pNewNode; // makes pHead point to the new node (because it got added to the front)
    }
}

int linked_list_get_size(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD; //we can't change where pCURR_NODE is pointing, so we have to change what it is pointing to
    int counter = 0;
    if (pCURR_NODE == nullptr) return counter; //if there are no nodes, the size is zero
    counter ++; // if there is at least one node, make the counter 1
    if (P_HEAD == P_TAIL) return counter; //if the first and last node are the same, the size is one

    Node* next_node = pCURR_NODE->pNext;; //initialize variable that will store the next node with the next node after the P_HEAD
    while (true){
    if (next_node == nullptr){ //if there is no next node, we are done
        break;
    }
    //otherwise: 
    counter ++; //add one to the counter, because there is another node
    next_node = next_node->pNext; //make next_node point to the node after the current_node
    }
    return counter;
}

int linked_list_get_value_at_position(const Node* const P_HEAD, const Node* const P_TAIL, const int POS) {
    
    const Node* pCURR_NODE = P_HEAD;
    Node* node;
    int counter = 0;
    // advance through list until end and count number of jumps

    if (pCURR_NODE == nullptr) throw out_of_range("The linked list has no nodes in it"); //if there are no nodes, we can't access values of nodes
    
    if (POS == 0){return pCURR_NODE -> value;} // if we are just looking for the value of the first node, we just need that value

    if (pCURR_NODE -> pNext != nullptr) 
    {node = pCURR_NODE -> pNext;}  //if the next node after the head exists, then we set the node we will be counting to be that node. We have to do this because pCURR_NODE and pHEAD are const
    else throw out_of_range("That position doesn't exist");


    while (true){
    counter ++; //add one to the counter, since we aren't just looking for the first node

    if (counter == POS){return node -> value;} //if the counter, which refers to the position of node in the linked list, is the position we are looking for, we return the value of node
    
    if (node->pNext == nullptr){ //if there is no next node, we are done, and the position doesn't exist
        throw out_of_range("There aren't that many nodes in the list");
    }

    //otherwise, if we our current position isn't the position we are looking for and there is a next position,

    node = node->pNext; //make next_node point to the node after the current_node
    }
}

void linked_list_set_value_at_position(Node* const P_head, Node* const P_tail, const int POS, const int VALUE) {
    // if trying to set an invalid spot, or list is empty - do nothing
    if (POS >= linked_list_get_size(P_head, P_tail) || POS <0) return;
    if (P_head == nullptr) return;

    Node* node = P_head;
    int counter = 0;
    // advance through list until end and count number of jumps
     while (true){
        if (POS == counter){
            node->value = VALUE; 
            return;
        }
    counter ++; //add one to the counter, since we aren't just looking for the first node
    //otherwise, if our current position isn't the position we are looking for and there is a next position,
    node = node->pNext; //make node point to the node after the current node
    }
    // if valid position, change value
    // otherwise do nothing
}

void linked_list_remove_node_at_front(Node*& pHead, Node*& pTail) {
    // if list is empty - do nothing
    if(pHead == nullptr) return;                
    
    // store pointer to current head
    Node* old_head = pHead;
    // advance head
    pHead = pHead->pNext;
    // if we're now pointing at nothing, list only had one element
    if(pHead == nullptr){ //therefore the tail is also null
    pTail = nullptr;

    }else{
    pHead->pPrev = nullptr; //make the previous pointer from the new head null
    }
    delete old_head;

}

void linked_list_add_value_to_back(Node*& pHead, Node*& pTail, const int VALUE) {
    // make new node
    Node* pNewNode = linked_list_make_node(VALUE);
    // if list is initially empty
    if (pHead == nullptr){
        // head and tail are the new node  
        pHead = pNewNode;
        pTail = pNewNode;     
    }
    else {
        // otherwise, chain off existing node
        pTail->pNext = pNewNode; // makes the current tail's pNext point to the new tail
        pNewNode->pPrev = pTail; // makes the new tail's pPrev point to the old tail
        pTail = pNewNode; //makes pTail pointer point to the new tail
    }               

}

void linked_list_remove_node_at_back(Node*& pHead, Node*& pTail) {
    // if list is empty, do nothing
    if(pTail == nullptr) return;
    // store pointer to current tail
    Node* old_tail = pTail;
    // move tail backwards
    pTail = pTail->pPrev;
    // if we're now pointing at nothing, list only had one element
    if (pTail == nullptr) {
        //  set head to also be null so it points to nothing
        pHead = nullptr;
        delete old_tail;
    }
        
    
    else{ // otherwise, list still has elements
        pTail->pNext = nullptr; // set next pointer to be null
        delete old_tail;
    }
}

void linked_list_add_value_before_position(Node*& pHead, Node*& pTail, const int POS, const int VALUE) {
    // if position is before the beginning, add to front
    if(POS <= 0 || pHead == nullptr) { //the or pHead == nullptr is a check for if the list is empty initially
        linked_list_add_value_to_front(pHead, pTail, VALUE);
    } 
    //if the position is after the end, add to back
    else if (POS >= linked_list_get_size(pHead,pTail)){
        linked_list_add_value_to_back(pHead, pTail, VALUE);
    }
    else{
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list until end and count number of jumps
        while (true){
            if (counter == POS){ // if we are at the position we were looking for,
                // make the new node that will be added into the linked list
                Node *pNewNode = linked_list_make_node(VALUE);
                // since we are adding before the position, we need to change the pointer chain of the current node and the node before it
                // previous node points to new node
                pCurrNode->pPrev->pNext = pNewNode;
                
                // new node points to previous node
                pNewNode->pPrev = pCurrNode->pPrev;

                // new node points to current node
                pNewNode->pNext = pCurrNode;
                // current node points to new node
                pCurrNode->pPrev = pNewNode;
                return;
            }
            // if we weren't at the desired position, we move current node to be the next
            pCurrNode = pCurrNode->pNext;
            counter ++; //advance the counter
        }
        

        
    }
}

int linked_list_min(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    
    // if list is empty
    if(pCURR_NODE == nullptr) {
        // throw exception
        throw out_of_range("list is empty");
    }

    // traverse list tracking min value present
    int minVal = pCURR_NODE->value;
    while (pCURR_NODE -> pNext != nullptr){ //while there is a next node
        pCURR_NODE = pCURR_NODE->pNext; // we are now checking the next node
        if (pCURR_NODE->value < minVal) minVal = pCURR_NODE ->value; //if its value is less than the current minVal, we update the minVal
    }
    

    return minVal;
}

int linked_list_max(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    
    // if list is empty
    if(pCURR_NODE == nullptr) {
        throw out_of_range("list is empty");
    }

    // traverse list tracking max value present

    int maxVal = pCURR_NODE->value;
     while (pCURR_NODE -> pNext != nullptr){
        pCURR_NODE = pCURR_NODE -> pNext;
        if (pCURR_NODE -> value > maxVal) maxVal = pCURR_NODE -> value;

     }
    

    return maxVal;
}

int linked_list_find(const Node* const P_HEAD, const Node* const P_TAIL, const int TARGET) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    if (pCURR_NODE == nullptr) return -1; //if the list is empty, return -1
    while (true){
        if (pCURR_NODE -> value == TARGET) return counter;

        pCURR_NODE = pCURR_NODE->pNext;
        counter ++;
        if(pCURR_NODE == nullptr) return -1; // we have gone through the list and not found the value
    }
    // if we get to here and the value hasn't been found, it is not in the list or the list is empty

    return -1;
}

void linked_list_remove_node_at_position(Node*& pHead, Node*& pTail, const int POS) {
    // if list is empty
    if(pHead == nullptr) {
        // do nothing
        return;
    } 
    
    // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        linked_list_remove_node_at_front(pHead, pTail);
        return;
    } else if (POS >= linked_list_get_size(pHead, pTail) -1) { // if the position is the final element or after list
        //remove from end
        linked_list_remove_node_at_back(pHead, pTail);
        return;}

    else {
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list until end and count number of jumps
        while (true){ // now that we've determined the node is within the list, we just have to iterate through the list, because there will be no infinite loop

            if (counter == POS){ //if we are at the position we are supposed to be at,
                
                // we need to link the node before the target node and after it
                pCurrNode ->pPrev ->pNext = pCurrNode -> pNext; //the previous node's next should point to the node after the node we're removing
                pCurrNode ->pNext ->pPrev = pCurrNode -> pPrev; //the next node's previous should point to the node before the node we're removing
                delete pCurrNode; //we need to deallocate the current node
                return;
            }
            counter ++;
            pCurrNode = pCurrNode->pNext; 
        } 
    }
    
}