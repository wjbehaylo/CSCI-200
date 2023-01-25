/* CSCI 200: Lab 3 A: L3A - Strings test suite
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     I looked up online how > and < work for strings, determining that a string is greater if it is after the other alphabetically/ has a lowercase where the other has an uppercase

 * Created functions that compare, test, and change strings, so that the test suite yields 100% correctness
 */

#include "string_functions.h"
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

unsigned long string_length(const string STR)  {
    unsigned long result =  STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR.substr(0,IDX) + TO_INSERT + STR.substr(IDX,STR.length()-IDX);
    return result;
}

unsigned long string_find(const string STR, const char C)  {
    unsigned long result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX,LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    int length = TEXT_TO_REPLACE.length();
    int total_length = STR.length();
    int IDX = STR.find(TEXT_TO_REPLACE);
    if (IDX == -1) return STR; //if the thing to replace isn't there, we don't do anything
    string result = STR.substr(0,IDX) + REPLACE_WITH + STR.substr(IDX+length, total_length-IDX-length); 
    // first goes in STR until we get to where the replacement starts, then puts in the replacement, 
    // then goes to the point after the replaced string, and puts in the rest of the string, which should be the total length minus the stuff we already put in minus the length of the replaced string.
    return result;
}

string string_first_word(const string STR)  {
    int word_end = STR.find(" ");
    string result = STR.substr(0,word_end);
    return result;
}

string string_remove_first_word(const string STR)  {
    int word_end = STR.find(" "); // finds the location of the first space (end of the first word)
    // apparently we aren't supposed to just remove the first word, but also the space after it, so I had to change it

    //if there is only one word, we return nothing
    if (word_end == -1) return "";
    string result = STR.substr(word_end+1, STR.length()-word_end-1);
    return result;
}

string string_second_word(const string STR)  {
    int word_end = STR.find(" ");
    if (word_end == -1) return ""; //in case no second word
    string result = STR.substr(word_end+1, STR.length() - word_end -1);
    word_end = result.find(" ");
    result = result.substr(0, word_end);
    // pretty much combined the first word return and first word removal
    return result;
}

string string_third_word(const string STR)  {
    int word_end = STR.find(" ");
    if (word_end == -1) return ""; //only one word
    string result = STR.substr(word_end+1,STR.length() - word_end - 1); // get rid of first word
    word_end = result.find(" ");
    if (word_end == -1) return ""; //only two words
    result = result.substr(word_end + 1, result.length() - word_end - 1); // get rid of second word
    word_end = result.find(" "); //finds where the word ends
    result = result.substr(0,word_end); //returns the third word, aka the first word after the other first two words have been removed
    
    return result;
}

string string_nth_word(const string STR, const int N)  {
    int word_end;
    string result = STR;
    for (int i = 1; i< N; i++){ // i needs to start as one, if we are doing the first word (we won't be doing the zeroth word)
        word_end = result.find(" ");
        if (word_end == -1) return ""; //there are too few words to send out the nth word
        result = result.substr(word_end+1,result.length() - word_end -1); //gets rid of whichever word is first right now
    }
    word_end = result.find(" ");
    result = result.substr(0,word_end);
    return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    string current_split = "";
    char current;
    for (unsigned int i = 0; i<STR.length();i++){
        current = STR[i];
        if (current == DELIMINATOR){
            result.push_back(current_split);
            current_split = "";
            continue;
        }
        current_split += current;
    }
    result.push_back(current_split); //necessary beceause the for loop doesn't send the last split to the vector
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result;
    for (unsigned int i = 0; i< STR.length(); i++){
        if (STR[i] == TARGET) {
            result += REPLACEMENT; //if the character is the target, we add replacement into result instead of it, then move onto the next character
            continue;}
        result += STR[i]; //if the character is not the target, we add it into result normally
    }
    return result;
}

string string_to_lower(const string STR) {
    // an interesting thing here is that STR is declared as a constant, so we can't just change it to lowercase, we have to make a copy of it
    string result;
    // now that we have a copy, we are able to just use the tolower function to make each character lowercase
    for (unsigned int i = 0; i<STR.length(); i++){
        result += tolower(STR[i]);
    }
    return result;
}

string string_to_upper(const string STR) {
    string result;
    
    for (unsigned int i = 0; i<STR.length(); i++){
        result += toupper(STR[i]);
    }
    return result;
}

int string_compare(const string LHS, const string RHS) {
    // if strings are equal, we return 0
    if (LHS == RHS) return 0;


    // left string < right string (before alphabetically or uppercase to the other's lowercase)
    if (LHS < RHS) return -1;

    // left string > right string (after it alphabetically or has a lowercase instead of an upper case)
    if (LHS > RHS) return 1;
    return 0;
}
