#ifndef MAZE_FUNCTIONS_H
#define MAZE_FUNCTIONS_H

//here is the header for our two search functions
#include <iostream>
#include <vector>
using namespace std;

/**
* @brief this function will print out a 2d array
* @param array this is the array to be printed
* @param rows this is the number of rows
* @param columns this is the number of columns
* @return no return, printing methods are all contained within
*/
void print(char** array, const int rows, const int columns);

/**
* @brief this function will go through an input maze using breadth first searching to find the end
* @param array this is the array that will be searched
* @param rows this is the number of rows present in our array
* @param columns this is the number of columns present in our array
* @param start this is an array with the starting index
* @return no return, because the printing methods are all contained
*/

void BFS(char**& array, const int rows, const int columns, vector<int> start);

/**
* @brief this function will go through an input maze using depth first searching to find the end
* @param array this is the array that will be searched
* @param rows this is the number of rows present in our array
* @param columns this is the number of columns present in our array
* @param start this is an array containing the starting index
* @return no return, because the printing methods are within the function
*/

void DFS(char**& array, const int rows, const int columns, vector<int> start);

#endif