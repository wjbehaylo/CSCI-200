#include <fstream> // step1, influde fstream
#include <iostream>
using namespace std;

int main() {
    
char operation;
double leftHandSide;
double rightHandSide;
double result;
string initial;

    //step 2 - declare our filestream variable
    // step 3 specify the file to open
    ofstream fileOut;
    fileOut.open("datafile.txt");
    cout << "Put in the numbers and the operator as a string: "<<endl;
    cin >> leftHandSide >> operation >> rightHandSide;
    fileOut << leftHandSide<<operation<< rightHandSide;


fileOut.close();

ifstream fileIn; //step 2, use ofstream if you are outputting
fileIn.open("datafile.txt"); //step 3 done, we could do the whole path if necessary or not in same directory

    //step 2 and 3 together
    // ifstream fileIn("datafile.txt");

    //step 4: verify the file opened
    /*if(fileIn.fail()){

    }*/
    
// or if(fileIn.is_open())
// or if(!fileIn)

// why would it fail?
// if the file doesn't exist, or we use the wrong name, 
// it exists but is in the wrong directory (not same as the code calling for it), 
// location is unavailable/doesn't exist

// step 5: read the data

fileIn >> leftHandSide >> operation >> rightHandSide;
    /*int x;
    while(fileIn >> x){


    }
    char x;
    double current_number;
    while (!fileIn.gof){
        x = fileIn.get();
        if (x== " " || x== "    " || x == "\n"){
            continue
        }
    }
    */
    switch(operation){
        case '+': result = leftHandSide + rightHandSide; break;
        
    }

    cout<< leftHandSide << " "<< operation << " "<< rightHandSide << " = "<< result;
fileIn.close(); 
}