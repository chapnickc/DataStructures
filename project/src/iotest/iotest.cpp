#include "Graphl.h"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main () {

  ofstream xfile;
  xfile.open ("example.txt");
  xfile << "Writing this to a file.\n";
  xfile.close();
  return 0;

  string line;
  ifstream yfile ("example.txt");
  if (yfile.is_open()){
    while ( getline (yfile,line) ){
      cout << line << '\n';
    }
    yfile.close();
  }
  else {cout << "Unable to open file"; }


}
