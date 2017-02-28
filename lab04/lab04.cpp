#include "lstack.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int Nstrings = 4;
string expressions[] = {"43", "(5+3)","(9*(2+3))","((11+3)*(4+3))"};

LStack<char> exprStack;



bool isValidExpr(const string& expr){

  //exprStack.clear();
  exprStack.push('E');
 
  
  char c, s;
  int i = 0;
  while (i < expr.length()){
    cout << c << endl;

    c = expr[i]; 
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
    return false; 
  }
}

void testfunc(){
  bool valid;
  string expr;
  for (int k = 0; k < Nstrings; k++){
    cout << "\nEvaluating expression " << k <<  endl;
    expr = expressions[k];
    valid = isValidExpr(expr);

    if (valid){
      cout << "Expression " << k << " is valid" << endl;
    }
    else{
      cout << "Expression " << k << " is invalid!" << endl;
    }
  }
}


int main(){
  testfunc();
  return 0;
}

