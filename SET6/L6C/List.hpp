/* CSCI 200: LAB 6 C:  L6C The Abstract List
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //  How to impliment a purely virtual function. I knew what it meant in theory, but I wasn't sure of proper syntax
 */


#ifndef LIST_HPP
#define LIST_HPP
 template<typename T>
 class List{
    public:
    
    List(){
        mSize = 0;
    }

    int getSize() const {
        return mSize;
    }

    virtual T get(const int POS) const = 0; //I had to do research but apparently this is how you initialize it in the abstracted class
    
    virtual void set(const int POS, const T VALUE) = 0;

    virtual void insert(const int POS, const T VALUE) = 0;

    virtual void remove(const int POS) = 0;

    protected:
    int mSize;

 };

 #endif