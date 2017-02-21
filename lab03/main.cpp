#include <string>
#include <iostream>
#include "lstack.h"

using namespace std;

LStack<char> parenStack;

char test0[] = "((())())()\0";
char test1[] = ")()(\0";

bool checkParens(const char* parenstr){
  for (int i = 0; i < strlen(parenstr); i++){
    cout << parenstr[i] << endl;;
  }
  return true;
}

int main(){
  bool check0 = checkParens(test0);
  bool check1 = checkParens(test1);
  return 0;
}
