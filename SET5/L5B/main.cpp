/* CSCI 200: LAB 5 B: L5B Recursion II: Merge Sort
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // looked up how to deallocate vectors to avoid memory leaks
 * Impliment a recursive merge sort function for linked lists
 */

 #include "mergesort.hpp"
 #include "LinkedList.hpp"
 #include <iostream>
 #include <vector>
 using namespace std;

 int main(){
        LinkedList<int>* list = new LinkedList<int>;
        list->insert(0,4);
        list->insert(1,3);
        list->insert(2,8);
        list->insert(3,1);
        list->insert(4,5);
        list->insert(5,9);
        list->insert(6,7);
        list->insert(7,2);
        list->insert(8,6);
        list->print();
        
        
        mergesort(list);
        list->print();
        delete list;
        return 0;

    }