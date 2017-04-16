#include "grlist.h"

#include "json.hpp"

#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using json = nlohmann::json;
using namespace std;

struct person {
  int age;
  std::string name;
  std::string address;
};


void export_json(json& j, ostream& output){
  output << setw(4) << j << endl;
}


void import_json(const json& j, person& p) {
    p.name = j.at("name").get<std::string>();
    p.address = j.at("address").get<std::string>();
    p.age = j.at("age").get<int>();
}


int main(){
  json j;
  j["name"] = std::string("John Goodman");
  j["address"] = std::string("10 Cloverfield Lane");
  j["age"] = 61;

  person p;
  import_json(j, p);
  cout << "name: " << p.name << endl;
  cout << "age: " << p.age << endl;
  cout << "address: " << p.address <<endl;

  ofstream outfile("graphtest.json");
  export_test(j, outfile);


}

