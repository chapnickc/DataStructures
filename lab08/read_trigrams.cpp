#include <iostream>
#include "book.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;


void read_freqs(FILE* fp){
  /* Read a list of strings and frequencies from standard input,
   * building a list of Huffman coding tree nodes */
  char buff[100];
  char buff2[100];
  char *ptr;
  char *ptr2;
  int freq;

  // Read number of chars
  Assert(fgets(buff, 99, fp) != NULL, "Couldn't read character count");
  ptr = buff;

  Assert(isdigit(*ptr) != 0, "Must be a digit here.");
  int count = atoi(ptr);


  // Read in the frequencies
  for (int i=0; i<count; i++) { 
    // Read the next entry
    Assert(fgets(buff, 99, fp) != NULL, "Ran out of codes too early");
    //cout << buff << endl;
    // process the entry, creating a new HuffTree
    for(ptr=buff; *ptr==' '; ptr++);  // Read first word
    Assert(*ptr == '"', "First char was not a quote mark.");

    for (ptr2=buff2, ptr++; *ptr!='"'; ptr++){
      *ptr2++ = *ptr;
    }
    cout << string(buff2) << endl;
    *ptr2 = '\0'; // End of string

    for (ptr++; *ptr==' '; ptr++);
    Assert(isdigit(*ptr) != 0, "Must be a digit here.");

    freq = atoi(ptr);
    //cout << freq << endl;
  }

}

int main(int argc, char** argv){
  double total = 0;
  FILE *fp;  // The file pointer


  // Check command line parameter for frequency file
  Assert(argc == 2, "Usage: huffman <frequency file>");
  Assert((fp = fopen(argv[1], "rt")) != NULL, "No such file");

  cout << "Read frequencies\n";
  read_freqs(fp);


}
