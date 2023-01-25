#include <fstream>
#include <iostream>
#include <cstring> //for the substrings during open_files 
using namespace std;

/* CSCI 200: Assignment 2: A2 - PPM Image editor
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // I went to office hours to get help understanding how the code is supposed to work and how I can do debugging with it
 *     // I also looked up how to write an array for the extra credit portion
 * 
 * Take in a base PPM file and, by transfering the RGB values of the bits, essentially put a filter on it to either turn it to grayscale or invert it
 */



int print_file_options(){ //the first function, just tell the user what the image options are
    cout<< "Which image to load?"<< endl;
    cout<< "  1. Brick"<<endl;
    cout<< "  2. Wallpaper"<< endl;
    cout<< "  3. Private"<< endl;
    return 3;
}


int print_operation_options(){ //second function, tell user the configurations they can do on the files
cout<< "Which process to apply?"<<endl;
cout<< "  1. Grayscale"<< endl;
cout<< "  2. Inversion"<< endl;
cout<< "  3. Mirror"<<endl;
return 3;
}



int get_user_input(int number_of_choices){
    int choice;
    while(true){
    cout<< "Enter ";
    for(int i=1; i<(number_of_choices+1); i++){
        if (i== number_of_choices){
            cout<< "or "<< i;
            break;
        }
        cout<< i<< ", ";
    }
    cout<< ": ";
    cin >> choice;
    if (!cin.fail() && choice >=1 && choice <= number_of_choices){
        cin.ignore(10000,'\n');
        break;
    }
    cin.clear(); // clear the fail state
    cin.ignore(10000,'\n'); // get rid of everything else in that line of input
    cerr << "Invalid input."<< endl;
    
}
return choice;
}



bool open_files(ifstream& fileIn, ofstream& fileOut, int file_choice, int operation){ //opens the correct files based on the User's inputs, and makes sure that they open correctly.
    string file_read;
    string file_write;
    switch (file_choice){ //based on user input, switch the string file_read to the # file we want to be reading pixel data from
        case 1: file_read = "input\\brick.ppm"; break;
        case 2: file_read = "input\\wallpaper.ppm";break;
        case 3: file_read = "input\\private";break;
    }
    file_write = "output\\" + file_read.substr(6,file_read.find(".")-6); //since the file we are writing to should have the first part of the file we are reading from, we can set it to a substring of the read file
    switch (operation){ // based on the operation, we decide what the file written to will be
        case 1: file_write +="_grayscale.ppm";break;
        case 2: file_write +="_inverted.ppm";break;
        case 3: file_write +="_mirrored.ppm";break;
    }
    fileIn.open(file_read);
    fileOut.open(file_write);
    if(fileIn.is_open() && fileOut.is_open()){
        cout<< "Opening "<< file_read.substr(6,file_read.length()-6)<<" file"<<endl;
        cout<< "Writing "<< file_write.substr(7,file_write.length()-7)<<" file"<<endl;
        return true;
    }
    else{
        return false;
    }
}



bool read_header_information(ifstream& fileIn, int& width, int& height, int& max_value){ //this initializes the width, height, and max value variables, as well as makes sure that we are reading the correct type of ppm, we use a reference operator for fileIn to make sure the cursor keeps moving after we read in those values
    string type;
    fileIn>> type;
    fileIn>> width;
    fileIn>> height;
    fileIn>> max_value;
    if (type == "P3"){
        return true;
    }
    else { 
        return false;
    }
}



void write_header_information(ofstream& fileOut, const int width, const int height, const int max_value){// this writes 
    fileOut<< "P3"<<endl;
    fileOut<< width<<" ";
    fileOut<< height<<endl;
    fileOut<< max_value<<endl;
}


void read_and_write_modified_pixels(ifstream& fileIn, ofstream& fileOut, const int operation, const int width, const int height, const int max_value){
    int red;
    int green;
    int blue;
    if (operation == 1){
        int gray;
        for (int i = 0; i< height; i++){
            for (int j = 0; j< width; j++){
                fileIn>> red >> green >> blue;
                gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
                fileOut<< gray<<" "<<gray<<" "<<gray<< " ";
            }
            fileOut<< "\n";
        }
    }
    else if (operation == 2){ 
        for (int i = 0; i<height; i++){
            for (int j = 0; j<width; j++){
                fileIn>> red>> green>> blue;
                red = max_value - red;
                green = max_value - green;
                blue = max_value - blue;
                fileOut<< red<<" "<<green<<" "<<blue<< " ";
            }
            fileOut<< "\n";
        }

    }
    else if (operation == 3){ // for the mirror, I used an array with all the pixels as elements, then went through and switched the first pixel of the row with the last, second with second to last, etc
        for (int i = 0; i<height; i++){
            int row [width][3];
            for (int j = 0; j<width; j++){
                fileIn>> row[j][0] >> row[j][1] >> row[j][2];
                }
            for (int j = width-1; j>=0; j--){
                fileOut<< row[j][0]<< " "<< row[j][1]<< " "<< row[j][2]<< " ";
                }
            fileOut<< "\n";
            }
        }
    }