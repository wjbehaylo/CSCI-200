/* CSCI 200: Assesment 3: A3 - Green Eggs and Ham
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // I looked up the ASCII value of 'A' for the count_letters function
        // went to office hours to get help with reading all words from a file (was using !fileIn.fail, needed to use !fileIn.eof)
 * Read in a file of text, and then separate it into words, remove punctuation, and sort it
 */

 #include <fstream>
 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <iomanip>

 using namespace std;

int digits(unsigned int number){
    int biggest_count_digits = 1;
    while (true){ // here we get how many digits there are in the number
        if (number >= 10) { // if the number is greater than 10, it has at least 1 more digit 
            number /= 10; //we divide it by 10 to move to the next place
            biggest_count_digits ++; // we add one to the number of digits
            continue;
        }
        else break; //once we finally get to where biggest_count is in the ones place, we know it has no more digits, so we are dont
        //note that if there is only one digit in the biggest_count, it won't trigger the above if statement and we will just exit, so digit is initialized to 1
    }
return biggest_count_digits;
}


 bool open_file(ifstream& fileIn, const string filename){
    fileIn.open(filename);
    if (fileIn.is_open()) return true;
    else return false;
 }

 vector<string> read_words_from_file(ifstream& fileIn){
    vector<string> word_list;
    string temp;
   
    while (!fileIn.eof()){
        fileIn>> temp;
        if (!fileIn.fail()){
        word_list.push_back(temp);
        }
    }

    return word_list;
 }

void remove_punctuation(vector<string>& string_vect, const string punctuation){
    string word;
    string temp_word;
    for (unsigned int i = 0; i< string_vect.size(); i++){
        word = string_vect.at(i);
        temp_word = "";
        for (unsigned int j = 0; j<word.length(); j++){ //this goes through every character in the current word
            for (unsigned int k = 0; k<punctuation.length(); k++){ // this is gonna go through each character in punctuation
                if (word[j] == punctuation[k]){
                    break;
                }
                else if( k == punctuation.length()-1){ // if we're at the last instance and it hasn't been one of the punctuation, we can send it to the word without punctuation
                    temp_word += word[j];
                }
            }


        }
        string_vect.at(i) = temp_word;
    }
}

void capitalize_words(vector<string>& string_vect){
    for (unsigned int i = 0; i<string_vect.size(); i++){
        for (unsigned int j = 0; j< string_vect[i].length(); j++){
            string_vect.at(i)[j] = toupper(string_vect[i][j]); //this makes each ch
        }

    }
}

vector<string> filter_unique_words(const vector<string> string_vect){
    vector<string> unique_words;
    string current_word;
    string temp;
    for (unsigned int i = 0; i<string_vect.size(); i++){
        current_word = string_vect[i];
        if (i == 0){ // just for the first one, because initially there isn't anything in the list of unique words
            unique_words.push_back(current_word);
            continue;
        }
        for (unsigned int j = 0; j< unique_words.size(); j++){ //we are going to see if the current word is a unique word
            temp = unique_words[j];
            if (current_word == temp){
                break; // it isn't a unique word
            }
            if (j == unique_words.size()-1){ // if it hasn't been a duplicate and we are on the last check, it is unique
                unique_words.push_back(current_word);
            }

        }
    }
    // now that we have a list of unique words in order of occurance, we need to go through and figure out the order alphabetically
    for (unsigned int i = 1; i< unique_words.size(); i++){
        for (int j = i-1; j >= 0; j--){ //we need to go backwards through the vector, putting the word in front of all the words its before
            
            if (unique_words.at(j+1) < unique_words.at(j)){ //if a word at j+1(initially i) is less than the word at j, they are swapped
                temp = unique_words.at(j); // make temp the word before it
                unique_words.at(j) = unique_words.at(j+1); // put it into the place the word before it was
                unique_words.at(j+1) = temp; // put the word before it into its place
            }
            else break;
        }
        }
        return unique_words;
    }

vector<unsigned int> count_unique_words(vector<string> string_vect, vector<string> unique_words){
    vector<unsigned int> unique_count;
    unsigned int current_count;
    string current_word;
    for (unsigned int i = 0; i<unique_words.size(); i++){ //for each unique word
        current_count = 0;
        current_word = unique_words[i];
        for (unsigned int j = 0; j<string_vect.size(); j++){ //we need to compare it with each word
            if (current_word == string_vect[j]) current_count ++; //if the unique word we are looking at the occurences of is the word in string_vect, we add one to the count
        }
        unique_count.push_back(current_count);
    }
    return unique_count;
}

void print_unique_word_counts(vector<string> unique_words, vector<unsigned int> unique_count){
    unsigned int longest_word_length = unique_words[0].length();
    unsigned int biggest_count = unique_count[0];
    
    for (unsigned int i = 1; i<unique_words.size(); i++){ //this gets us the length of our longest word and the most time any word occurs
        if (longest_word_length < unique_words[i].length()) longest_word_length = unique_words[i].length();
        if (biggest_count < unique_count[i]) biggest_count = unique_count[i];
    }
    int biggest_count_digits = digits(biggest_count);

    for (unsigned int i = 0; i<unique_words.size(); i++){
        cout<< left<<setw(longest_word_length)<< unique_words.at(i) << " : ";
        cout<< right <<setw(biggest_count_digits)<< unique_count.at(i) << endl;
    }
}

void count_letters(vector<string> string_vect, unsigned int letter_count[26]){
    //letters have an ascii value when added to things, so I plan on using that to help the computer determine which letter is which. 'A' is 65, 'Z' is 90
    // so by subtracting 65 from the letter, I should be able to get which letter it is
    // however, we need to use the freestore since it is dynamic memory
    for (unsigned int i = 0; i<string_vect.size(); i++){ //this iterates us through each string
        for (unsigned int j = 0; j< string_vect[i].length(); j++){ // this iterates us through each letter of each string
            letter_count[string_vect[i][j] - 65]++; //this adds one to the count of whichever letter it is
        }
    }

}

void print_letter_counts(const unsigned int letter_count[26]){
    // first we have to find the most occurances of any letter
    unsigned int biggest_count = 0;
    for (int i = 0; i<26; i++){
        if (biggest_count < letter_count[i]) biggest_count = letter_count[i];
    }
    int biggest_count_digits = digits(biggest_count);

    for (int i = 0; i < 26; i++){
        cout << char(i+65)<<": "<<right<< setw(biggest_count_digits) << letter_count[i] << endl;

    }
}

void print_max_min_letter(const unsigned int letter_count [26]){
    unsigned int min_occurences = letter_count[0]; // we have to initialize them to some value
    char min_occurences_letter = 'A';
    unsigned int max_occurences = letter_count[0];
    char max_occurences_letter = 'A';
    for (int i = 1; i< 26; i++){ // this loop goes through the count of each letter, updating the min and max occurences' values, and the letter they represent
        if (min_occurences > letter_count[i]){ // if its lower
            min_occurences = letter_count[i]; // make it the new minimum
            min_occurences_letter = char(i + 65); // and record the letter
        }
        if (max_occurences < letter_count[i]){ // if its higher
            max_occurences = letter_count[i]; // make it the new maximum
            max_occurences_letter = char(i+65); // and record the letter
        }
    }
    int total_letters = 0;
    for (int i = 0; i <26; i++){ //here we get the total amount of letters for the percentages
        total_letters += letter_count[i];
    }
    double min_percentage = (double(min_occurences) / total_letters) * 100;
    cout<< "Least Frequent Letter: "<< min_occurences_letter <<" "<< right << setw(digits(max_occurences))<< min_occurences<< " (";
    cout<< right<< setw(7) <<fixed << setprecision(3) << min_percentage << "%)"<< endl;

    double max_percentage = (double(max_occurences) / total_letters) * 100;
    cout<< " Most Frequent Letter: "<< max_occurences_letter << " "<< right << setw(digits(max_occurences))<< max_occurences<< " (";
    cout<< right<< setw(7) <<fixed <<setprecision(3) << max_percentage << "%)"<< endl;

}