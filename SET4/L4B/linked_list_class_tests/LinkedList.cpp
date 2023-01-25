/* CSCI 200: LAB 4 B: L4B A linked list class test suite
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // went to office hours to find out how to prototype functions for classes effectively (with @param etc)
 * create a linked list class with data types and member functions that can correctly pass the test suite
 */

#include "LinkedList.h"
#include "Node.h"
#include <iomanip> //for the exception syntax 
#include <exception>
using namespace std;

LinkedList::LinkedList() {
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}

LinkedList::~LinkedList() {
    mSize = 0;
    Node* temp;

    //we need to start at mpHead and go until we are at mpTail, deleting every node on the way, until mpHead's next node is a nullptr, meaning we've reached the end of the list
    while (mpHead->pNext != nullptr){
        temp = mpHead->pNext; //this sets a temporary variable to the next node
        delete mpHead; //so that we can deallocate the current head
        mpHead = temp; //then we make the temp the new head
    }
    //now mpHead should point to the last node in the linked list
    delete mpHead; //we deallocate the final node, and then make the head and tail nullpointers
    mpHead = nullptr;
    mpTail = nullptr;
}

// although its technically out of turn, we define the size function earlier so that we can use it in later functions
unsigned int LinkedList::size(){
    return mSize;
}

Node* LinkedList::mMakeNodeForValue(const int VALUE){
    Node* pNode = new Node;
    pNode -> pPrev = nullptr;
    pNode -> pNext = nullptr;
    pNode -> value = VALUE;
    return pNode;
}

int LinkedList::get(const int POS){
    Node* curr_node = mpHead;
    if (curr_node == nullptr) throw out_of_range("Empty List");
    int counter = 0;
    
    while (curr_node != nullptr){
        if (counter == POS) return curr_node ->value;
        counter ++;
        curr_node = curr_node ->pNext;
    }
    throw out_of_range("Position not in list");
}

int LinkedList::find(const int TARGET){
    Node* curr_node = mpHead;
    int counter = 0;
    while(curr_node != nullptr){ // if we are not dealing with the end of the list
        if (curr_node ->value == TARGET) return counter; //if the value at the present node is the target, return which node # the present node is
        //otherwise, move to the next node by incriminting the counter and changing curr_node
        counter++; 
        curr_node = curr_node ->pNext;
    }
    //if the TARGET value was not stored at one of the nodes, we return -1
    return -1;
}



void LinkedList::insert(const int POS, const int VALUE){
    mSize ++; //we are adding a value so the list's size increases
    Node* curr_node = mpHead;
    Node* insert_node = mMakeNodeForValue(VALUE); //here we make the new node to be inserted
    if(curr_node == nullptr){// if the list is empty
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
        counter ++;
        curr_node = curr_node->pNext;
    }
    //if we've gotten to this point without exiting, that means that the node must not be within the size of the list, so we add it to the back
    insert_node ->pPrev = mpTail; // previous of new tail is old tail
    mpTail ->pNext = insert_node; //next of old tail is new tail
    mpTail = insert_node; //new tail is set
    return;
}

int LinkedList::max(){
    if (mpHead == nullptr) throw out_of_range("Empty list"); //throw out of range if list is empty
    Node* curr_node = mpHead; //initialize our iterator for the nodes
    int max = curr_node ->value; //initialize max value

    while (curr_node != nullptr){ //as long as we aren't at the end of the list,
        if (curr_node->value > max) max = curr_node ->value; //check if the value of the current node is bigger than our current max, if so, change current max
        curr_node = curr_node ->pNext; //move to the next node
    }
    //once we get here we've gone through every node, so whatever the value is now is correct
    return max;
}

int LinkedList::min(){
    if (mpHead == nullptr) throw out_of_range("Empty list");
    Node* curr_node = mpHead; //make our current node iterator
    int min = curr_node ->value; //initialize minimum value
    while (curr_node !=nullptr){ //while we are still going through the list,
        if (curr_node -> value < min) min = curr_node->value; //if the value of the current node is a new minimum, change the minimum
        curr_node = curr_node ->pNext; //move to next node of list
    }
    //once we get here we've gone through every node, so whatever the value is now is correct
    return min;
}

void LinkedList::remove(const int POS){
    
    if (mpHead != nullptr){
        mSize--; //if the list isn't empty, we will be shrinking the list
    }
    Node* curr_node = mpHead;
    if (mpHead == mpTail) {// if the list only has one element, we will remove and deallocate that one element
        delete mpHead;
        mpHead = nullptr;
        mpTail = nullptr;
        return;
    }

    if (POS <= 0){ //if the position is 0 or less, we are removing and deallocating the first element of the list
        curr_node = curr_node ->pNext; //use curr_node as a temporary value to get what the next mpHead will be
        delete mpHead; //deallocate the current pHead
        mpHead = curr_node; //make curr_node the new mpHead
        mpHead ->pPrev = nullptr; //make sure that the new head doesn't point to the previous head
        return;
    }
    if (POS >= size()){ //if the position is the last element or is past the last element, we remove the last element
        curr_node = mpTail->pPrev; // use curr_node as a temporary value for what the new mpTail will be
        delete mpTail; //get rid of old mpTail
        mpTail = curr_node; //make curr_node the new mpTail
        mpTail ->pNext = nullptr; //make sure that the new tail doesn't point to the previous tail
        return;
    }

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

void LinkedList::set(const int POS, const int VALUE){
    if (POS < 0 || POS > size() -1) return; //if the position is not in the list, the function does nothing
    Node* curr_node = mpHead;
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