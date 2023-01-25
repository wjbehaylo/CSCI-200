/* CSCI 200: Assessment 5 : A5 a-MAZE-ing
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // 
 * use stack, queue, and 2d lists to solve a maze
 */

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>
 #include "maze_functions.h" //where the searches are
 using namespace std;



 int main(int argc, char* argv[]){
    string filename;
    ifstream FileIn;
    if(argc == 1){
        cout<<"Enter input file name: ";
        cin>> filename;
        FileIn.open(filename);
    }
    else {
        FileIn.open(argv[1]);
    }

    if (!FileIn.is_open()){
        cout<<"File doesn't exist. Quitting program.";
        return -1;
    }
    cout<< "File opened successfully!"<<endl<<endl;
    int rows, columns;
    vector<int> start(2);
    char current_element;
    FileIn>>rows>>columns;
    
    char** maze = new char*[rows]; //maze is a pointer to the first of many dynamically allocated lists that are each row
    
    for (int i = 0; i<rows; i++){ //each row will be one dimension of the array
        maze[i] = new char[columns]; //row i is a dynamically allocated array of j (number of columns) characters
        for (int j = 0; j<columns; j++){ //each column will be the other dimension    
            FileIn >> current_element; //bring in the next element of the file 
            if (current_element == 'S'){
                start[0] = i; //record the row and column of the start
                start[1] = j;
            }
            maze[i][j] = current_element; //add that element into our array
        }
    }
    FileIn.close(); //now that we have our array made, we can close the input file

    int search; //this is where the search method we have selected will be recorded
    cout<<"Enter 1 to search via BFS"<<endl<<"Enter 2 to search via DFS"<<endl<<"Choice: ";
    cin>>search;
    if (search ==1){
        BFS(maze, rows, columns, start);
    }
    else if (search ==2){
        DFS(maze, rows, columns, start);
    }

    delete[] maze; //make sure that we aren't doing any memory leaks
    maze = nullptr; //or dangling pointer errors
    return 0;
 }