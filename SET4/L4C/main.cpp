/* CSCI 200: LAB 4 C: L4C a templated linked list class
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // to know where to start, worked with Jonas Edelstein on understanding how to use templates
 * create a templated linked list class
 */

 #include "Node.hpp"
 #include "LinkedList.hpp"
 #include <exception>
 #include <iomanip>
 using namespace std;

 int main(){
    LinkedList<int> intlist1;
    intlist1.insert(0,6);
    intlist1.insert(0,5);
    intlist1.insert(5,7);
    intlist1.insert(-3,1);
    intlist1.insert(1,2);
    intlist1.insert(2,9);
    intlist1.insert(2,3);
    intlist1.print();
    intlist1.set(3,4);
    intlist1.print();
    intlist1.remove(-2);
    intlist1.remove(9);
    intlist1.remove(2);
    cout<<intlist1.get(2)<<endl;
    cout<<intlist1.size()<<endl;
    intlist1.print();

    LinkedList<int> intlist2;
    cout<< intlist2.size()<<endl;
    intlist2 = intlist1; //this is where our error happens
    cout<< "List 1 size "<<intlist1.size()<<endl << "List 2 size "<<intlist2.size()<<endl;

    intlist2 + intlist1;
    intlist2.print();
    intlist1.print();

    // i finished the implimentation but didn't have enough time to complete this main.cpp file or the makefile
    return 0;
 }