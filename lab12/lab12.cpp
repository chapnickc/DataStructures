#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* from hell's heart I stab at thee; 
 * for hate's sake I spit my last breath at thee. 
 */

string read_book(istream& file){
  string word;
  string book("");
  while (file >> word){ 
    book += " " + word; 
  }
  return book;
}


void build_suffix_tree(Trie& trie, string& s){
  string substring;
  string::iterator it, end;
  end = s.end();
  for (it = s.begin(); it < s.end(); ++it){
    substring.assign(it, end);
    trie.insert(substring.c_str(), 1);
  }
}


string find_longest_substring(string& s1, string& s2){
  Trie trie;
  build_suffix_tree(trie, s1);

  int result;
  int longest = 0;
  
  string substring;
  string::iterator it, end, save;
  end = s2.end();

  for (it = s2.begin(); it < end; ++it){
    substring.assign(it, end);
    result = trie.longestPrefix(substring.c_str());
    if (result > longest) {
      longest = result;
      save = it;
    }
  }

  substring.assign(save, save+longest);
  return substring;
}



int main(){
  
  ifstream file;

  file.open("./mobydick.txt");
  string mobydick = read_book(file);
  file.close();

  file.open("./startrek.txt");
  string startrek = read_book(file);
  file.close();

  string substring = find_longest_substring(mobydick, startrek);
  cout << substring << endl;

  return 0;
}
