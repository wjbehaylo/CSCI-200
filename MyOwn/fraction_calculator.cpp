#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
using namespace std;

string f1;
int num1;
int den1;
int num2;
int den2;
int num_sol; // numerator of solution
int cden; //common denominator
int mid1;
int mid2;
string sol;
string f2;
string operation;
char cont = 'Y';

int main()
{
    while (cont == 'Y'){
    cout<< "Enter the fractions you want to compute, separating numerator and denominator with a /: "<<endl<<"1: ";
    cin>> f1;
    cout << "2: ";
    cin >> f2;
    cout << endl;
    cout << "Enter the operation you would like to do (+, -, /, *)"<<endl;
    cin >> operation;
    mid1 = f1.find("/");
    mid2 = f2.find("/");
    num1 = stoi(f1.substr(0,mid1));
    den1 = stoi(f1.substr(mid1+1,f1.length()-mid1));
    num2 = stoi(f2.substr(0,mid2));
    den2 = stoi(f2.substr(mid2+1,f2.length()-mid2));
    
    if (operation == "+"){
        cden = den1 * den2;
        num1 *= den2;
        num2 *= den1;
        num_sol = num1 + num2;
        
    }
    else if (operation == "-"){
        cden = den1 * den2;
        num1 *= den2;
        num2 *= den1;
        num_sol = num1-num2;

    }
    else if (operation == "*"){
        num_sol = num1 * num2;
        cden = den1 * den2;
    }
    else if (operation == "/"){
        num_sol = num1 * den2;
        cden = num2 * den1;
    }
    for (int i =2; i<=7; i++ ){
    while (num_sol%i == 0 && cden %i == 0){
            num_sol /=i;
            cden /=i;
        }
    }
    if (cden ==1){
        cout << f1 << " "<< operation << " "<< f2 << " = "<< num_sol<< endl;
    }
    else {
        cout << f1 <<" "<< operation<<" " << f2 << " = "<< num_sol << "/" << cden<< endl;
    }
    cout << "Do you want to do another? (Y/N) ";
    cin >> cont;
    } 

return 0;
}