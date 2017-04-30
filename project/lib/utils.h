#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, std::string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << std::endl;
    exit(-1);
  }
}


#endif
