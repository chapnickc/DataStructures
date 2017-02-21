#include <string>
#include <iostream>
#include "lstack.h"
#include "astack.h"

using namespace std;


LStack<char> parenStack;
char test0[] = "((())())()";
char test1[] = ")()(";

bool checkParens(const char* parenstr){
  /* Checks for balanced parentheses */
  int matches = 0;
  for (int i = 0; i < strlen(parenstr); i++){
    // use ' ' instead of " " since  looking at single char
    if (parenstr[i] == '('){ 
      parenStack.push(parenstr[i]); 
    } 
    else if (parenstr[i] == ')' && parenStack.length() > 0) {
      parenStack.pop();
      matches++;
    }
    else {
      cout << "\tParentheses not balanced!" << endl;
      return false;
    }
  }
  cout << "\tFound " << matches << " balanced parentheses."<< endl;
  return true;
}


int main(){
  bool balanced;

  cout << "Testing string 0" << endl;
  balanced = checkParens(test0);

  cout << "\nTesting string 1" << endl;
  balanced = checkParens(test1);

  cout << "\nExiting..." << endl;
  return 0;
}

