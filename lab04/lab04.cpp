#include "lstack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

LStack<char> exprStack;   // stack to help evaluate expression

string expressions[] = {
  "43", "(5+3)","(9*(2+3))","((11+3)*(4+3))", 
  ")4=8","525600", "((((2))))","(9000)",
  "(4*8)+(3*4)","((4*8)+(3*4))","abcd", "(E1+E2)",
  "(1400*(1+2+3+4+5+6+7+8+9+10)*100))",
  "(1+2)+(3+4)",
  "((1+2)+(3+4))"};

size_t N = sizeof(expressions)/sizeof(expressions[0]);


bool isValidExpr(const string& expr){

  exprStack.clear();
  exprStack.push('E');
 
  char c, s;
  int i = 0;
  while (i < expr.length()){
    c = expr[i]; 
    if (not (exprStack.length() > 0)){
      return false;
    }
    s = exprStack.topValue();

    if ( c == ')' && s == ')')
      { exprStack.pop(); i++; }

    else if (c == '(' && s == '(') 
      { exprStack.pop(); i++; }

    else if ((c == '*' || c == '+') && s == 'O')
      { exprStack.pop(); i++; }

    else if (isdigit(c) && s == 'E') { 
      exprStack.pop(); 
      do { i++; } while( isdigit(expr[i]) );
    }

    else if (c == '(' && s == 'E'){
      exprStack.pop();
      exprStack.push(')');
      exprStack.push('E');
      exprStack.push('O');
      exprStack.push('E');
      exprStack.push('(');
    }

    else { return false; }
  }

  if (exprStack.length() == 0){ 
    return true; 
  }
  else { 
    exprStack.clear();
    return false; 
  }
}


void testfunc(){
  bool valid;

  for (int k=0; k < N;k++){
    cout << "\nEvaluating " << expressions[k] <<  " ..." << endl;

    valid = isValidExpr(expressions[k]);

    if (valid){ cout << "\t\tLooks good!" << endl; } 
    else { cout << "\t\tInvalid!" << endl; }
  }
}



int main(){
  testfunc();
  return 0;
}

