/* CSCI 200: Lab 2 A: L2A - The Secret Moosage
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // none

 * Read in a file that is encoded, decode it, and write it out to another, decipherable file
 */

 #include <fstream>
 #include <iostream>

 using namespace std;

 int main(){
    //open files and declare their streams
    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("secretMessage.txt");
    fileOut.open("decipheredMessage.txt");

    //check for error
    if(!fileIn.is_open() || !fileOut.is_open()){
        cerr << "Error opening files";
        return -1;
    }
    
    //write data
    char c;
    while ( fileIn.get(c)){
        if(c == '~'){
            fileOut<<' ';
        }
        else if (c == '\n'){
            fileOut<<'\n';
        }
        else {
            fileOut<< char(c+1);
    }
    }
//close files
fileIn.close();
fileOut.close();

return 0;
 }