/* CSCI 200: LAB 5 C: L5B Needle in a Haystack
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // 
 * Use our sorting mechanisms to generate a random list of numbers and find a number in it
 */

 #include <iomanip>
 #include <vector>
 #include <cmath>
 #include <time.h>
 #include "mergesort.hpp"
 #include "binary_search.hpp"
 using namespace std;




 int main(){
    int list_size;
    int min, max;
    int random_number;
    int number_of_searches;
    srand(time(0));
    cout<< "Enter the number of numbers to be stored in the list: ";
    cin>> list_size;
    list_size *=10;
    cout<< "Enter the minimum and maximum for each number."<<endl<<"Min: ";
    cin>>min;
    cout<< "Max: ";
    cin>>max;
    LinkedList<int>* list = new LinkedList<int>;
    for (int i = 0; i<(list_size); i++){
        random_number = (rand() % (max - min + 1)) + min; //generates a random number between the maximum and minimum
        list->insert(i,random_number);
    }
    list->print();
    mergesort(list);
    list->print();
    cout<< "Enter the number of searches: ";
    cin>> number_of_searches;

    int target_value;
    int position;
    for (int i = 0; i<number_of_searches; i++){
        cout<<"Search #"<<i+1<<endl;
        cout<<"Enter target value: ";
        cin>> target_value;
        position = binary_search(list, target_value); //name, target
        if (position == -1){
            cout<< "That value is not in the list."<<endl;
        }
        else{
            cout<<"The value "<<target_value<<" is at position "<<position<<endl;
        }
        list->print();
    }

return 0;



 }