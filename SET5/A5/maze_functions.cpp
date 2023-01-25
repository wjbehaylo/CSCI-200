//here are the implimentation of all of the functions

#include "maze_functions.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

void print(char** array, const int rows, const int columns){
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            cout<< array[i][j];
        }
        cout<<endl;
    }
    return;
}

void BFS(char**& array, const int rows, const int columns, vector<int> start){
    char wall('#'), open('.'), end('E'), visited('@'), begin('S');
    LinkedList<vector<int>> queue; //queue is gonna be a linked list of integer vectors
    queue.insert(0,start); //inserts start to be the beginning of the queue

    vector<int> current_element(2); //the current element being checked/changed, a 2 element array storing row and column
    vector<int> next_element(2);

    while (queue.size() != 0){ //while the queue isn't empty (which should only happen if we are done)
        current_element = queue.get(0); //we take from the front and add to the back, this makes the current element the front of the queue
        queue.remove(0); //as we are dealing with this element, it is no longer in the queue, so it can be removed
        if (array[current_element[0]][current_element[1]] == visited) continue; //if we've already searched through the current node, this is pointless because its adjacent nodes will be on the queue already

        if (array[current_element[0]][current_element[1]] == end){ //if the value in the array at the point stored in current element is 'E', we are done
            cout<< "End was reached!"<<endl; 
            print(array,rows,columns);
            return;
        }
        //since we weren't at the end, we need to make the value at that position in the array our visited indicator 
        if(array[current_element[0]][current_element[1]] != begin) array[current_element[0]][current_element[1]] = visited;

        // now we need to add to the back of the list the elements adjacent to our current element that can be traversed to. This excludes places already gone to or walls
        
        //check left and right, means we must see if we are in the edge columns, can be done by seeing what the second index of current_element is
        if (current_element[1] == 0){ //if we are in the first column, we only need to add the spot to the right to the queue
            //so check that it is not a wall or visited,
            if((array[current_element[0]][current_element[1]+1] != visited) && (array[current_element[0]][current_element[1]+1] != wall) && (array[current_element[0]][current_element[1]+1] != begin)){
                next_element[0] = current_element[0]; next_element[1] = current_element[1] +1;
                queue.insert(queue.size(),next_element); //we add to the back, so whenever adding an element this is the easiest way
            }
        }
        else if (current_element[1] == columns-1){ //if we are in the last column, we only need to check the element to the left
            if((array[current_element[0]][current_element[1]-1] != visited) && (array[current_element[0]][current_element[1]-1] != wall) && (array[current_element[0]][current_element[1]-1] != begin)){
                next_element[0] = current_element[0]; next_element[1] = current_element[1] -1;
                queue.insert(queue.size(),next_element);
            }
        }
        else {//if we aren't at the first or last column, we add the elements on the left and right to the queue, so we combined the two
            
            //checking and adding left element
            if((array[current_element[0]][current_element[1]-1] != visited) && (array[current_element[0]][current_element[1]-1] != wall) && (array[current_element[0]][current_element[1]-1] != begin)){
                next_element[0] = current_element[0]; next_element[1] = current_element[1] -1;
                queue.insert(queue.size(),next_element);
            }
            //checking and adding right element
            if((array[current_element[0]][current_element[1]+1] != visited) && (array[current_element[0]][current_element[1]+1] != wall) && (array[current_element[0]][current_element[1]+1] != begin)){
                next_element[0] = current_element[0]; next_element[1] = current_element[1] +1;
                queue.insert(queue.size(), next_element);
            }
        }

        //now we check up and down to make sure that we add all the necessary adjacent tiles
        if (current_element[0] == 0){ //if we are in the first row, we need to only add whats underneath
            if((array[current_element[0]+1][current_element[1]] != visited) && (array[current_element[0]+1][current_element[1]] != wall) && (array[current_element[0]+1][current_element[1]] != begin)){
                next_element[0] = current_element[0] +1; next_element[1] = current_element[1];
                queue.insert(queue.size(), next_element);
            }
        }
        else if (current_element[0] == rows-1){ //if we are in the last row, only need to add whats above
            if((array[current_element[0]-1][current_element[1]] != visited) && (array[current_element[0]-1][current_element[1]] != wall)&& (array[current_element[0]-1][current_element[1]] != begin)){
                next_element[0] = current_element[0] -1; next_element[1] = current_element[1];
                queue.insert(queue.size(), next_element);
            }
        }
        else { //if we aren't in the first or last row, we add the value one above and one below
            //adding above
            if((array[current_element[0]+1][current_element[1]] != visited) && (array[current_element[0]+1][current_element[1]] != wall) && (array[current_element[0]+1][current_element[1]] != begin)){
                next_element[0] = current_element[0] +1; next_element[1] = current_element[1];
                queue.insert(queue.size(),next_element);
            }
            //adding below
            if((array[current_element[0]-1][current_element[1]] != visited) && (array[current_element[0]-1][current_element[1]] != wall) && (array[current_element[0]-1][current_element[1]] != begin)){
                next_element[0] = current_element[0] -1; next_element[1] = current_element[1];
                queue.insert(queue.size(), next_element);
            }
        }
    }
    cout<< "End cannot be reached."<<endl; //if we have gotten to this point,it means that the queue is empty, meaning we've searched all possible points, and none of them have been the end
    
    print(array,rows,columns); //also, we have changed all the . of placed that have been checked to @, so our final array should be what we want it to be in terms of checked indices.
}



void DFS(char**& array, const int rows, const int columns, vector<int> start){
    char wall('#'), open('.'), end('E'), visited('@'), begin('S');
    LinkedList<vector<int>> stack; //the stack gets added to the end of and removed from the end of as well
    stack.insert(stack.size(),start); //makes start the beginning of the queue

    vector<int> current_element(2);
    vector<int> next_element(2);
    char value;
    while (stack.size() != 0){ //when the stack is 0, we have searched every available position
        //first we have to check the current position to see if it is the end
        current_element = stack.get(stack.size()-1); // makes current element
        stack.remove(stack.size()); //removes it from the end of the stack, since it is being addressed currently. We will still add the ones adjacent to it to the stack
        if (array[current_element[0]][current_element[1]] == visited) continue; //if we've already searched through the current node, this is pointless because its adjacent nodes will be on the queue already
        if (array[current_element[0]][current_element[1]] == end){
            cout<<"End was reached!" <<endl;
            print(array,rows,columns);
            return;
        }
        //now that we have checked if the current node is the correct node, (and it isn't), we will say that it has been searched
        //since we weren't at the end, we need to make the value at that position in the array our visited indicator 
        if(array[current_element[0]][current_element[1]] != begin) array[current_element[0]][current_element[1]] = visited;



        //first we add what is above the current element
        if(current_element[0]-1 >= 0) { //if we are not at the first row, add what's above if it is allowed
            value = array[current_element[0]-1][current_element[1]]; //make value the value above 
            next_element[0] = current_element[0]-1;
            next_element[1] = current_element[1];
            if (value != visited && value != wall && value != begin){
                stack.insert(stack.size(),next_element);
            }
        }
        //now we add whats is left of the current element
        if(current_element[1] -1 >=0){ //if we are not at the most left column, we can check what is to the left
            value = array[current_element[0]][current_element[1]-1];
            next_element[0] = current_element[0];
            next_element[1] = current_element[1] -1;
            if (value != visited && value != wall && value != begin){
                stack.insert(stack.size(),next_element);
            }
        }

        //now we add what is below the current element, so we have to make sure it is not in the last row
        if(current_element[0] +1 != rows){ //if this is true, we are not in the last row
            value = array[current_element[0]+1][current_element[1]];
            next_element[0] = current_element[0]+1;
            next_element[1] = current_element[1];
            if (value != visited && value != wall && value != begin){
                stack.insert(stack.size(),next_element);
            }
        }

        //now we add the element to the right of the current element, which we can only do if it is not in the last column
        if(current_element[1] +1 != columns){ 
            value = array[current_element[0]][current_element[1]+1];
            next_element[0] = current_element[0];
            next_element[1] = current_element[1]+1;
            if (value != visited && value != wall && value != begin){
                stack.insert(stack.size(),next_element);
            }
        }
        //now we have added to the stack, with the next one being the value to the right, etc, so upon execution


    }
    cout<< "End cannot be reached."<<endl; // if we have gotten here, the stack is empty, so we have swept the maze
    print(array,rows,columns); // we also shoudl've changed any . to @, so we can print the traversed maze


    return;


}