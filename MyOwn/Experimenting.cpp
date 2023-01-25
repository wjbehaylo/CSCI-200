#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

class Book{
  public:
    Book(){
      title = "The C++ Programming Language";
      author = "Bjarne Stroustrup";
      publicationYear = 1986;
    }
    Book(const string TITLE, const string AUTHOR, const int PUBYEAR){
      author = AUTHOR;
      title = TITLE;
      publicationYear = PUBYEAR;
    }

    void setAuthor(const string NEWAUTHOR){
      author = NEWAUTHOR;
    }

    void setTitle(const string TITLE){
      title = TITLE;
    }

    void setPubYear(const int PUBYEAR){
      publicationYear = PUBYEAR;
    }
    string getAuthor() const{
      return author;
    }
    string getTitle() const{
      return title;
    }
    int getPublicationYear() const{
      return publicationYear;
    }
  private:
    string author, title;
    int publicationYear;

};

class Library{
  private:
    LinkedList<Book*>* catalog;
  public:
    Library(){
      catalog = new LinkedList<Book*>(); //the () makes it call the default constructor I guess?
    }

    Library(const Library& OTHER){
      Book* newBook;
      catalog = new LinkedList<Book*>;
      for (int i = 0; i<OTHER.catalog->size(); i++){
        newBook = new Book(OTHER.catalog->get(i)->getTitle(), OTHER.catalog->get(i)->getAuthor(), OTHER.catalog->get(i)->getPublicationYear());
        catalog->insert(i,newBook);
      }
    }

    Book* checkoutBook(const string TITLE){
      Book* found = nullptr;
      for(int i = 0; i<catalog->size(); i++){
        if(catalog->get(i)->getTitle() == TITLE) {found = catalog->get(i); return found;}
      }
      return found; //if the function hasn't returned returned found by now, the book doesn't exist so we just return a nullptr 
    }

    void returnBook(Book* returned){
      catalog->insert(catalog->size(),returned); //insert to the end of the catalog (which is a pointer) the pointer to the returned book
      return;
    }
};

int main() {
  int input1;
  int decimaloutput = 0;
  cout<<"Would you like to go from binary to decimal (Enter 1)"<<endl<<"Or decimal to binary (Enter 2)"<<endl;
  cin>>input1;
  string binaryinput, binaryoutput("");
  int decimalinput;
  if (input1 ==1){
    cout<<"Enter binary input: "<<endl;
    cin>>binaryinput;
    //at this point the input is stored in input2, a string
    for(int i = binaryinput.length()-1; i>=0; i--){
      if(binaryinput[i] == '0') continue;
      decimaloutput += 1*pow(2,i);
    }
    cout<<decimaloutput;
  }
  else if(input1 ==2){
    cout<<"Enter decimal input: "<<endl;
    cin>>decimalinput;
    vector<int> remainder;
    int quotient = -1;
    while (quotient != 0){
      quotient = decimalinput/2;
      remainder.push_back(decimalinput%2); //remainder is whats left over
      decimalinput = quotient;
    }
    for(int i=remainder.size()-1; i>=0;i--){
      if (remainder.at(i) == 0) binaryoutput+="0";
      else binaryoutput+="1";
    }
    cout<<binaryoutput<<endl;



  }

  return 0;
}