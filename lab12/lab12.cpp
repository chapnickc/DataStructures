#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* from hell's heart I stab at thee; 
 * for hate's sake I spit my last breath at thee. 
 */

int main(){
  Trie trie;
  ifstream file;
  file.open("./mobydick.txt");
  string word;
  string mobydick("");
  string startrek("");

  while (file >> word){
    mobydick += word;
  }
  file.close();


  file.open("./startrek.txt");
  while (file >> word){
    startrek += word;
  }
  file.close();


  string substring;
  string::iterator it;
  string::iterator end;
  end = mobydick.end();

  for (it = mobydick.begin(); it < mobydick.end(); ++it){
    substring.assign(it, end);
    trie.insert(substring.c_str(), 1);
  }

  int longest = 0;
  int result;
  string::iterator save;
  end = startrek.end();
  for (it = startrek.begin(); it < end; ++it){
    substring.assign(it, end);
    result = trie.longestPrefix(substring.c_str());
    if (result > longest) {
      longest = result;
      save = it;
    }
  }
  cout << longest << endl;
  substring.assign(save, save+longest);
  cout << substring << endl;

  return 0;
}
