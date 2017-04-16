#include "grlist.h"
#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>


#include "json.hpp"
using json = nlohmann::json;
using namespace std;

struct person {
  int age;
  std::string name;
  std::string address;
};


void export_json(ostream& output){
  json j;
  j["graph"] = { 
    { "directed", false }, 
    { "type", "graph type" }, 
    { "label", "graph label" },
    { "metadata", 
      { "user-defined", "values" }
    }
  };

  j["nodes"] = {"none"};
  j["edges"]= {"none"};

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
  cout <<"name: " << p.name <<endl;
  cout << "age: "<< p.age <<endl;
  cout << "address: "<< p.address <<endl;

  ofstream outfile("graphtest.json");
  export_json(outfile);


  int numvert = 10;
  Graphl graph(numvert);
  cout << "initial |E|: " << graph.e() << endl;
  cout << "initial |V|: " << graph.n() << endl;

}

