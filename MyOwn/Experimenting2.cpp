#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void upString(string& input){
    for (int i = 0; i<input.length(); i++){
        input[i] = toupper(input[i]);
    }
}

int main(){
string test = "tEsT StRIng";

upString(test);
cout<<test;

return 0;
}