#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/**
* @brief this is my own function, used in the print statements to determine how many digits are in a number
* @param number this is the number we are determining the digits of
* @return this function returns an integer of the number of digits
*/
int digits(unsigned int number);

/** 
* @brief this function opens the input stream for the program from the user=entered file, and checks for error
* @param fileIn the ifstream the user has opened, will open filename
* @param filename the string name of the file the user wants to read, won't change,
* @return the function returns a bool, true if the file opened, false if it didn;t
*/
bool open_file(ifstream& fileIn, const string filename);


/**
* @brief takes the words from the filestrean and puts them into a vector, in order
* @param fileIn its the input filestream we are reading the words from
* @return the function returns a vector containing all of the words present in the file
*/
vector<string> read_words_from_file(ifstream& fileIn);

/** 
* @brief gets rid of any punctuation in our words
* @param string_vect this is the vector containing all of our strings
* @param punctuation this is the string that has the punctuation, it doesn't change
* @return no return, 
*/
void remove_punctuation(vector<string>& string_vect, const string punctuation);

/**
* @brief this makes it so that all of the letters in all the strings are fully capitalized
* @param string_vect this vector contains our words to be capitalized, when complete they will be capitalized
* @return no return, 
*/
void capitalize_words(vector<string>& string_vect);

/**
* @brief this function gets the unique words from the vector of strings, in order
* @param string_vect this vectors contains the words we will be determining the uniqueness of, we don't change this though
* @return returns a vector of the strings that are unique from the parameter vector
*/
vector<string> filter_unique_words(const vector<string> string_vect);

/**
* @brief this counts the occurances of each unique word
* @param string_vect this is the vector containing all the words
* @param unique_words this is the vector containing all the strings
* @return this returns a vector of unsigned integers representing how many times each unique word occurs in string_vect
*/
vector<unsigned int> count_unique_words(const vector<string> string_vect, const vector<string> unique_words);

/** 
* @brief this prints out each word with the number of times it occurs next to it
* @param unique_words this vector contains the unique words we are printing the occurances of
* @param unique_count this vector contains the amount of times each unique word occured
* @return void, doesn't return anything, just prints out the list
*/
void print_unique_word_counts(const vector<string> unique_words, const vector<unsigned int> unique_count);

/**
* @brief this function counts how many times each letter occurs in the total text
* @param string_vect this is the vector containing all the words we are counting the letters in
* @param letter_count this is a 26 element array (one for each letter of alphabet) where we will set each element's number to the number of times it's respective letter occurs
* @return nothing, the letter_count array is passed by reference and changed during
*/
void count_letters(const vector<string> string_vect, unsigned int letter_count[26]);

/**
* @brief this function prints each letter, with the number of times it occurred next to it
* @param letter_count this is an array of how many times each letter occurred
* @return no return, as it just prints the values from the array
*/
void print_letter_counts(const unsigned int letter_count[26]);

/**
* @brief this function prints out the two letters that occur most and least often, if there are multiple it prints the first alphabetically
* @param letter_count this contains the amount of times each letter occurred
* @return no return, just prints which letters were most and least common
*/
void print_max_min_letter(const unsigned int letter_count[26]);



#endif
