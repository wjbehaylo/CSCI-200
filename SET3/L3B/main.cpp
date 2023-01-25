/* CSCI 200: Lab 3 B: L3B - Pointers
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // None
 * Complete a variety of tasks to gain familiarity with pointers
 */


#include <iostream>
using namespace std;

int main(){
    int iNum = 9;
    double dNum = 14.25;

    int* pINum1;
    int* pINum2;

    double* pDNum;

    pINum1 = &iNum; 
    //here we are establishing that this is the address of iNum we are pointing to, if we were to point to it without the &,
    //  we would get an error from trying to match a pointer to an int and an int (rather than a memory spot with an int)
    cout<< "Pointer Address: " << pINum1 << " iNum Address: "<< &iNum<< endl; // they are the same, because the pointer is pointing to the address that is then referenced


    cout<< "The value of INum, displayed using *pINum1 is: "<<*pINum1<< endl; //we use the dereferencing operator to call the thing stored in that memory address, rather than the actual memory address

    // pINum2 = &dNum; //the error message is: 
    /*main.cpp: In function 'int main()':
main.cpp:29:14: error: invalid conversion from 'double*' to 'int' [-fpermissive] */

    // this error message is due to trying to assign an integer pointer to a double type
     pDNum = &dNum;

     cout<<"Address of dNum is: "<< pDNum<<" Value of dNum is: " <<*pDNum<<endl;

    iNum = 7;

    cout<<"Value of iNum: "<<*pINum1<<endl;

 pINum2 = pINum1; // this should make pINum2 a pointer to the address that pINum1 is 
    cout<< "The address in pINum2 is: "<<pINum2<<endl;

    cout<< *pINum2<< endl;

*pINum2 = 12;
cout<<"Now we're gonna output the value in iNum in three ways."<<endl;
cout<<"1: using the variable iNum to access it's memory address: "<<endl<< iNum<<endl;
cout<<"2: dereferencing the pointer pINum1, to print the value stored in the memory address it's pointing to (which is the memory address of iNum): "<<endl<< *pINum1<< endl;
cout<<"3: dereferencing the pointer pINum2, to print the value stored in its memory address, which is the memory address of pINum1, which is the memory address of iNum: "<<endl<< *pINum2<<endl;

return 0;
}

