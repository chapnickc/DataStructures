#include <string>
#include <iostream>
#include "lstack.h"
#include "astack.h"

using namespace std;

LStack<int> parenStack;

char test0[] = "((())())()";
char test1[] = ")()(";
char test2[] = "((((((((";


bool checkParens(const char* parenstr){
  /* Checks for balanced parentheses */
  for (int i = 0; i < strlen(parenstr); i++){
    if (parenstr[i] == '('){ 
      parenStack.push(i); 
    } 
    else if (parenstr[i] == ')' && parenStack.length() > 0) {
      parenStack.pop();
    }
    else if (parenstr[i] == ')' && parenStack.length() == 0) {
      // extra right paren
      return false;
    }
  }

  // if we didn't empty the stack, get the position 
  // of the offending left parent
  if (parenStack.length() > 0) {
    return false;
  }
  return true;
}


int checkParenPos(const char* parenstr){
  /* Checks for balanced parentheses */
  //parenStack.clear();
  for (int i = 0; i < strlen(parenstr); i++){
    if (parenstr[i] == '('){ 
      parenStack.push(i); 
    } 
    else if (parenstr[i] == ')' && parenStack.length() > 0) {
      parenStack.pop();
    }
    else if (parenstr[i] == ')' && parenStack.length() == 0) {
      // extra right paren
      return i;
    }
  }

  // if we didn't empty the stack, get the position 
  // of the offending left parent
  if (parenStack.length() > 0) {
    return parenStack.pop();
  }

  return -1;
}

void testfunc(const char* teststr){
  bool balanced;
  int pos;
  cout << "\nTesting string: \"" << teststr <<"\""<< endl;
  balanced = checkParens(teststr);
  pos = checkParenPos(teststr);
  if (pos == -1){
    cout << "\tNo offending parentheses!" << endl;
  }
  else {
    cout << "\tOffending parenthesis at position: "<< pos << endl;
  }
}


int main(){
  testfunc(test0);
  testfunc(test1);
  testfunc(test2);

  cout << "\nExiting..." << endl;
  return 0;
}

