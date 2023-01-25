#ifndef ppm_functions_h
#define ppm_functions_h

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

/**
* @brief prints the three files the user can choose from
* @return returns the number of file options there are
*/
int print_file_options();

/**
* @brief prints the three operations the user can choose from
* @return the number of operations there are
*/
int print_operation_options();

/**
* @brief gets user input from 1 to a number, makes sure it works
* @param number_of_choices is an integer that represents how many options there are to choose from
* @return returns the user choice between the three options
*/
int get_user_input(int number_of_choices);

/**
*@brief opens the input and output files, makes sure that they opened
*@param fileIn the file we will be reading from, during this we decide what file that is
*@param fileOut the file we will be writing to, during this we create that file
*@param file_choice the file the user chose, corresponds to bricks, wallpaper, or private
*@param operation the operation the user chose, used to name the output file
*@return returns true if the files opened successfully, false if there was an error
*/
bool open_files(ifstream& fileIn, ofstream& fileOut, int file_choice, int operation);
   
/**
*@brief reads the header of the file we are reading from, puts the values of width, height, max value into their respective variables
*@param fileIn is the file we are reading, pbr so that the cursor updates
*@param width the amount of pixels in a row of the ppm
*@param height the amount of pixels in a column of the ppm
*@param max_value the maximum of R,G,or B values in a pixel
*@return returns true if the file is the right type of PPm, false if its not
*/
bool read_header_information(ifstream& fileIn, int& width, int& height, int& max_value);

/**
*@brief writes the headers to the file we are writing to
*@param fileOut is the ofstream for the file we are writing to
*@param width is the width of the ppm image
*@param height is the height of the ppm image
*@param max_value is the maximum integer value of R, G, or B in a single pixel
*@return doesn't return anything, since this function is not computing, just writing to our file
*/
void write_header_information(ofstream& fileOut, const int width, const int height, const int max_value);

/**
*@brief reads the original pixels from the ifstream, modifies them, and writes them to the ofstream
*@param fileIn is the if stream for the file we are reading from
*@param fileOut is the of stream for the file we are writing to
*@param operation decides how we will be computing/altering the input bits
*@param width number of pixels in a row we are writing to or reading from
*@param height number of pixels in a column we are writing to or reading from
*@param max_value the maximum value of R,G, or B in a pixel
*@return no return, since it is modifying the files within it
*/
void read_and_write_modified_pixels(ifstream& fileIn, ofstream& fileOut, const int operation, const int width, const int height, const int max_value);
#endif