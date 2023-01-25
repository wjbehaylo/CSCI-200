#include "word_functions.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // check program was started correctly
    if(argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        cerr << "  filename   - file to open upon start" << endl;
        return -2;
    }

    // get filename to open
    string filename = argv[1];
    
    // open file for parsing
    ifstream fileIn;
    if( !open_file(fileIn, filename) ) {
        cerr << "Could not open file \"" << filename << "\"" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    }

    // read all the words in the file
    vector<string> allWords = read_words_from_file( fileIn );
    fileIn.close();
    cout << "Read in " << allWords.size() << " words" << endl;

    // clean the words to remove punctuation and convert to uppercase
    const string PUNCTUATION_TO_REMOVE = "?!.,;:\"()_-'&[]";
    remove_punctuation(allWords, PUNCTUATION_TO_REMOVE);
    capitalize_words(allWords);

    // find only the unique words in the file
    vector<string> uniqueWords = filter_unique_words(allWords);
    cout << "Encountered " << uniqueWords.size() << " unique words" << endl;
    
    // count the occurrences of each unique word in the entire text
    vector<unsigned int> uniqueWordCounts = count_unique_words(allWords, uniqueWords);
    print_unique_word_counts(uniqueWords, uniqueWordCounts);

    // count the occurrences of every letter in the entire text
    unsigned int letters[26] = {0};
    count_letters(allWords, letters);
    print_letter_counts(letters);

    // print statistics on letter frequencies
    print_max_min_letter(letters);

    return 0;
}