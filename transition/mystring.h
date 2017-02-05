#include <iostream>
using namespace std;

class mystring {

  private:
    char* data;         // do this since it's not statically allocated
    int allocated;


    // this is for good design
    void resize(int newsize);

  public:
    mystring();
    mystring(const char* str);
    mystring(const mystring& m);
    ~mystring();
    // this will find the terminator (ASCII) value in the 
    //A null terminatedd list has the ascii 
    //
    int length() const;
    void operator+=(const mystring& other);

    // strictly speaking, this should be outside of the class, 
    // but we need access to the private data
    friend ostream& operator<<(ostream& out, const mystring& ms);
};

