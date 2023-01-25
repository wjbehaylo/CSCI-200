#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include <exception>
#include <iostream>
using namespace std;


template <typename T>
class LinkedList {
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
    * @brief an integer representing the number of nodes in the list
    */
    unsigned int mSize; 
    
    /**
    * @brief makes a node of given value, with null pointers for pNext and pPrev
    * @param VALUE the  value to be stored in the node
    * @return Node* pointer to the newly created node
    */ 
    Node<T>* mMakeNodeForValue(const T VALUE);

    public:

    /**
    * @brief copy constructor that creates a deep copy of a different linked list
    * @param OTHER other is a reference to the linked list that will be copied
    */
    LinkedList(const LinkedList<T>& OTHER);

    /**
    * @brief Copy assignment operator that deallocated the existing list (if any) and does a deep copy of the other list
    * @param OTHER represents the list that will be copied
    */
    LinkedList<T>& operator=(const LinkedList<T>& OTHER);

    LinkedList<T>& operator+(const LinkedList<T>& OTHER);

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
    T get(const int POS) const;

    /**
    * @brief finds the first occurance of a value in the list
    * @param TARGET the target value that will be searched for in the list
    * @return returns the index of the position where the TARGEt was found if found, otherwise returns -1
    */
    int find(const T TARGET) const;

    /**
    * @brief inserts a node into the list, at the beginning or end if the specified POS is before or after the list, respectively
    * @param POS the position that the node will be inserted into
    * @param VALUE the value of the node that will be inserted
    */
    void insert(const int POS, const T VALUE);

    void print(){ //prints all the values in the list
        
            Node<T>* curr_node = mpHead;
            while(curr_node != nullptr){
            cout<< curr_node ->value <<" ";
            curr_node = curr_node->pNext;
            }
            cout<< endl;

    }
    /**
    * @brief finds the maximum value within a linked list
    * @return the maximum value of the list
    * @throws out_of_range if the list is empty
    */
    T max() const;
    /** 
    * @brief finds the minimum value within a linked list
    * @return the minimum value of the list
    * @throws out_of_range if the list is empty
    */
    T min() const;

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
    
    void set(const int POS, const T VALUE);

    /**
    * @brief gets and returns the current size of the list
    * @return returns the size of the list, stored above in mSize
    */
    unsigned int size() const;

};
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& OTHER){
    if( OTHER.size() == 0){ //if the other list is empty, so is the new one
        mpHead = nullptr;
        mpTail = nullptr;
        mSize = 0;
    }
    else { //otherwise, we need to insert a node at the end of our list for each node in their list, with the same value
        mpHead = new Node<T>;
        int size = OTHER.size();
        mSize = 0; //makes new head and tail for this array
        for(int i = 0; i<size; i++){ //for each node in the other we make a node in our new list with the same value
            insert(i, OTHER.get(i)); // we make and insert a node into the list with the value of the respective node of the other list, which should always be a value that the list doesn't have yet, adding it to the end
        }
        }
        
    }

template<typename T> // operator overload, returns a LinkedList passed by reference (so it can be changed later) 
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER){ //this function should just be a combination of our destuctor and the deep copy function above
    Node<T>* temp = new Node<T>;
    mSize = 0;
    if(mpHead != nullptr){
    //we need to start at mpHead and go until we are at mpTail, deleting every node on the way, until mpHead's next node is a nullptr, meaning we've reached the end of the list
    while (this->mpHead->pNext != nullptr){
        temp = this->mpHead->pNext; //this sets a temporary variable to the next node
        delete this->mpHead; //so that we can deallocate the current head
        this->mpHead = temp; //then we make the temp the new head
    }
    //now mpHead should point to the last node in the linked list
    cout<< this->mpHead->value;
    delete this->mpHead; //we deallocate the final node, and then make the head and tail nullpointers
    this->mpHead = nullptr;
    this->mpTail = nullptr;
    }
    //now that we have deallocated the current LinkedList, we can copy OTHER and make it our linked list
    for(int i = 0; i<OTHER.size(); i++){ //for each node in the other we make a node in our new list with the same value
            this->insert(i,OTHER.get(i)); // we make and insert a node into the list with the value of the respective node of the other list, which should always be a value that the list doesn't have yet, adding it to the end
        }
    return *this; //we return the deferenced new list,
        }

    template<typename T>
    LinkedList<T>& LinkedList<T>::operator+(const LinkedList<T>& OTHER){
        for (int i = 0; i<OTHER.size();i++){
            this->insert(mSize+i,OTHER.get(i));
        }
        return *this;
    }


template<typename T>
LinkedList<T>::LinkedList() {
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList() {
    mSize = 0;
    Node<T>* temp;

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
template<typename T>
unsigned int LinkedList<T>::size() const{
    return mSize;
}

template<typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VALUE){
    Node<T>* pNode = new Node<T>;
    pNode -> pPrev = nullptr;
    pNode -> pNext = nullptr;
    pNode -> value = VALUE;
    return pNode;
}

template<typename T>
T LinkedList<T>::get(const int POS) const{
    Node<T>* curr_node = mpHead;
    if (curr_node == nullptr) {throw std::out_of_range("Empty List");}
    int counter = 0;
    
    while (curr_node != nullptr){
        if (counter == POS) return curr_node ->value;
        counter ++;
        curr_node = curr_node ->pNext;
    }
    throw std::out_of_range("Position not in list");
}

template<typename T>
int LinkedList<T>::find(const T TARGET) const{
    Node<T>* curr_node = mpHead;
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


template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE){
    mSize ++; //we are adding a value so the list's size increases
    Node<T>* curr_node = mpHead;
    Node<T>* insert_node = mMakeNodeForValue(VALUE); //here we make the new node to be inserted
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
template<typename T>
T LinkedList<T>::max() const{
    if (mpHead == nullptr) throw std::out_of_range("Empty list"); //throw out of range if list is empty
    Node<T>* curr_node = mpHead; //initialize our iterator for the nodes
    T max = curr_node ->value; //initialize max value

    while (curr_node != nullptr){ //as long as we aren't at the end of the list,
        if (curr_node->value > max) max = curr_node ->value; //check if the value of the current node is bigger than our current max, if so, change current max
        curr_node = curr_node ->pNext; //move to the next node
    }
    //once we get here we've gone through every node, so whatever the value is now is correct
    return max;
}
template<typename T>
T LinkedList<T>::min() const{
    if (mpHead == nullptr) throw std::out_of_range("Empty list");
    Node<T>* curr_node = mpHead; //make our current node iterator
    T min = curr_node ->value; //initialize minimum value
    while (curr_node !=nullptr){ //while we are still going through the list,
        if (curr_node -> value < min) min = curr_node->value; //if the value of the current node is a new minimum, change the minimum
        curr_node = curr_node ->pNext; //move to next node of list
    }
    //once we get here we've gone through every node, so whatever the value is now is correct
    return min;
}
template<typename T>
void LinkedList<T>::remove(const int POS){
    
    if (mpHead != nullptr){
        mSize--; //if the list isn't empty, we will be shrinking the list
    }
    Node<T>* curr_node = mpHead;
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
template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE){
    if (POS < 0 || POS > size() -1) return; //if the position is not in the list, the function does nothing
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
#endif