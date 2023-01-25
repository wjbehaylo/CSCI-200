#include "test_suite.h"
#include "string_functions.h"

#include <iomanip>
#include <iostream>
using namespace std;

const int MESSAGE_WIDTH = 45;

int test_int(int& testNum, const string MESSAGE, const int LHS, const int RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_unsigned_long(int& testNum, const string MESSAGE, const unsigned long LHS, const unsigned long RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_char(int& testNum, const string MESSAGE, const char LHS, const char RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_string(int& testNum, const string MESSAGE, const string LHS, const string RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_vector_string(int& testNum, const string MESSAGE, const vector<string>& LHS, const vector<string>& RHS) {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;

    bool vectorsMatch = (LHS.size() == RHS.size());
    if (vectorsMatch) {
        for(unsigned int i = 0; i < LHS.size(); i++) {
            if(LHS.at(i) != RHS.at(i)) {
                vectorsMatch = false;
                break;
            }
        }
    }
    if (vectorsMatch) {
        cout << "    PASSED   \n";
    } else {
        cout << " !!>FAILED<!! Returned: {";
        for(unsigned int i = 0; i < LHS.size(); i++) {
            cout << "\"" << LHS.at(i) << "\"";
            if(i < LHS.size() - 1) {
                cout << ", ";
            }
        }
        cout << "} != Expected: {";
        for(unsigned int i = 0; i < RHS.size(); i++) {
            cout << "\"" << RHS.at(i) << "\"";
            if(i < RHS.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}\n";
    }
    return vectorsMatch ? 1 : 0;
}

bool run_all_tests()  {
    int totalPassed = 0, totalNumTests = 0;
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_length()",              string_length("Now") , 3 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_length()",              string_length("Tablet") , 6 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_length()",              string_length("The length is 17.") , 17 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_length()",              string_length("") , 0 );
    totalPassed += test_char(          totalNumTests,  "Testing string_char_at()",             string_char_at("Elephant", 3) , 'p' );
    totalPassed += test_char(          totalNumTests,  "Testing string_char_at()",             string_char_at("Giraffe", 2) , 'r' );
    totalPassed += test_char(          totalNumTests,  "Testing string_char_at()",             string_char_at("Armadillo", 4) , 'd' );
    totalPassed += test_string(        totalNumTests,  "Testing string_append()",              string_append("There's a ", "natural mystic.") , "There's a natural mystic." );
    totalPassed += test_string(        totalNumTests,  "Testing string_append()",              string_append("It's the ", "eye of the tiger.") , "It's the eye of the tiger." );
    totalPassed += test_string(        totalNumTests,  "Testing string_append()",              string_append("", "Nothing to something.") , "Nothing to something." );
    totalPassed += test_string(        totalNumTests,  "Testing string_insert()",              string_insert("If you carefully.", "listen ", 7) , "If you listen carefully." );
    totalPassed += test_string(        totalNumTests,  "Testing string_insert()",              string_insert("carefully.", "Watch ", 0) , "Watch carefully." );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_find()",                string_find("Have to face reality now.", 'o') , 6 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_find()",                string_find("Have to face reality now.", 'e') , 3 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_find()",                string_find("Have to face reality now.", 'a') , 1 );
    totalPassed += test_unsigned_long( totalNumTests,  "Testing string_find()",                string_find("Have to face reality now.", 'q') , string::npos );
    totalPassed += test_string(        totalNumTests,  "Testing string_substring()",           string_substring("Such a natural mystic", 7, 7) , "natural" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substring()",           string_substring("Such a natural mystic", 8, 2) , "at" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substring()",           string_substring("Such a natural mystic", 0, 4) , "Such" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substring()",           string_substring("Something to nothing.", 0, 0) , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substring()",           string_substring("Something to nothing.", 10, 0) , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_replace()",             string_replace("Strings are not the way", "Strings", "Things") , "Things are not the way" );
    totalPassed += test_string(        totalNumTests,  "Testing string_replace()",             string_replace("Show me the things", "things", "way") , "Show me the way" );
    totalPassed += test_string(        totalNumTests,  "Testing string_replace()",             string_replace("Show me the things", "car", "way") , "Show me the things" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("The quick brown fox jumped over the lazy dog") , "The" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("A man a plan a canal Panama") , "A" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("I have the hang of this") , "I" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("Single") , "Single" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("Uh oh") , "Uh" );
    totalPassed += test_string(        totalNumTests,  "Testing string_first_word()",          string_first_word("") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_remove_first_word()",   string_remove_first_word("The quick brown fox jumped over the lazy dog") , "quick brown fox jumped over the lazy dog" );
    totalPassed += test_string(        totalNumTests,  "Testing string_remove_first_word()",   string_remove_first_word("Goodbye") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_remove_first_word()",   string_remove_first_word("") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_remove_first_word() twice",string_remove_first_word(string_remove_first_word("The quick brown fox jumped over the lazy dog")) , "brown fox jumped over the lazy dog" );
    totalPassed += test_string(        totalNumTests,  "Testing string_remove_first_word() twice",string_remove_first_word(string_remove_first_word("Goodbye")) , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("The quick brown fox jumped over the lazy dog") , "quick" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("A man a plan a canal Panama") , "man" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("I have the hang of this") , "have" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("Single") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("Uh oh") , "oh" );
    totalPassed += test_string(        totalNumTests,  "Testing string_second_word()",         string_second_word("") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()",          string_third_word("The quick brown fox jumped over the lazy dog") , "brown" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()",          string_third_word("A man a plan a canal Panama") , "a" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()", 	       string_third_word("I have the hang of this") , "the" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()", 	       string_third_word("Single") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()", 	       string_third_word("Uh oh") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_third_word()", 	       string_third_word("") , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(1)",           string_nth_word("The quick brown fox jumped over the lazy dog", 1) , "The" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(2)",           string_nth_word("The quick brown fox jumped over the lazy dog", 2) , "quick" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(3)",           string_nth_word("The quick brown fox jumped over the lazy dog", 3) , "brown" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(4)",           string_nth_word("The quick brown fox jumped over the lazy dog", 4) , "fox" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(5)",           string_nth_word("The quick brown fox jumped over the lazy dog", 5) , "jumped" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(6)",           string_nth_word("The quick brown fox jumped over the lazy dog", 6) , "over" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(7)",           string_nth_word("The quick brown fox jumped over the lazy dog", 7) , "the" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(8)",           string_nth_word("The quick brown fox jumped over the lazy dog", 8) , "lazy" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(9)",           string_nth_word("The quick brown fox jumped over the lazy dog", 9) , "dog" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(10)",          string_nth_word("The quick brown fox jumped over the lazy dog", 10) , "" );
    totalPassed += test_string(        totalNumTests,  "Testing string_nth_word(11)",          string_nth_word("The quick brown fox jumped over the lazy dog", 11) , "" );

    vector<string> tokens1 = {"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog"};
    totalPassed += test_vector_string( totalNumTests,  "Testing string_tokenize()",            string_tokenize("The quick brown fox jumped over the lazy dog", ' '), tokens1 );
    totalPassed += test_vector_string( totalNumTests,  "Testing string_tokenize()",            string_tokenize("The@quick@brown@fox@jumped@over@the@lazy@dog", '@'), tokens1 );

    vector<string> tokens2 = {"The quick brown fox jumped over the lazy dog"};
    totalPassed += test_vector_string( totalNumTests,  "Testing string_tokenize()",            string_tokenize("The quick brown fox jumped over the lazy dog", '*'), tokens2 );

    totalPassed += test_string(        totalNumTests,  "Testing string_substitute()",          string_substitute("The Gxxgle", 'x', 'o') , "The Google" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substitute()",          string_substitute("$chool of Mine$", '$', 's') , "school of Mines" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substitute()",          string_substitute("$chool of Mine$", '+', '*') , "$chool of Mine$" );
    totalPassed += test_string(        totalNumTests,  "Testing string_substitute() twice",    string_substitute(string_substitute("D--", '-', '+'), 'D', 'C') , "C++" );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_lower()",            string_to_lower("This SHOULD be LOWER case") , "this should be lower case" );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_lower()",            string_to_lower("MNASDF874792L[]//.;[\t],") , "mnasdf874792l[]//.;[\t]," );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_lower()",            string_to_lower("C++") , "c++" );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_upper()",            string_to_upper("This SHOULD be upper case") , "THIS SHOULD BE UPPER CASE" );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_upper()",            string_to_upper("mnasdf874792l[]//.;[\t],") , "MNASDF874792L[]//.;[\t]," );
    totalPassed += test_string(        totalNumTests,  "Testing string_to_upper()",            string_to_upper("c++") , "C++" );
    totalPassed += test_int(           totalNumTests,  "Testing string_compare()",             string_compare("C++", "c++") , -1 );
    totalPassed += test_int(           totalNumTests,  "Testing string_compare()",             string_compare("C++", "C++") , 0 );
    totalPassed += test_int(           totalNumTests,  "Testing string_compare()",             string_compare("c++", "C++") , 1 );
    totalPassed += test_int(           totalNumTests,  "Testing string_compare()",             string_compare("short", "shorter") , -1 );
    totalPassed += test_int(           totalNumTests,  "Testing string_compare()",             string_compare("longer", "long") , 1 );

    cout << endl;
    cout << "Tests Passed: " << setw(3) << right << totalPassed << " / " << setw(3) << totalNumTests << " (" << setprecision(0) << fixed << totalPassed * 100.0f / totalNumTests << "%)" << endl << endl;
    return (totalPassed == totalNumTests);
}