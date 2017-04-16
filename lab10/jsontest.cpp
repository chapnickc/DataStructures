#include "json.hpp"
#include <iostream>
#include <fstream>


// for convenience
using json = nlohmann::json;
using namespace std;

int main(){
  // read a JSON file
  std::ifstream filename("completesingle.json");
  json jsonGraph;
  filename >> jsonGraph;

  //cout << jsonGraph.dump() << endl;
  cout << jsonGraph["graph"]["nodes"]<< endl;
  /*// convert from JSON: copy each value from the JSON object*/
  //ns::person p {
      //j["name"].get<std::string>(),
      //j["address"].get<std::string>(),
      //j["age"].get<int>()
  //};

  json j;

  // add a number that is stored as double (note the implicit conversion of j to an object)
  j["pi"] = 3.141;
  j["happy"] = true;
  j["name"] = "Niels";
  j["nothing"] = nullptr;
  j["answer"]["everything"] = 42;
  j["list"] = { 1, 0, 2 };
  j["object"] = { {"currency", "USD"}, {"value", 42.99} };

  //cout << j.dump() << endl;


/*  // instead, you could also write (which looks very similar to the JSON above)*/
  //json j2 = {
    //{"pi", 3.141},
    //{"happy", true},
    //{"name", "Niels"},
    //{"nothing", nullptr},
    //{"answer", {
      //{"everything", 42}
    //}},
    //{"list", {1, 0, 2}},
    //{"object", {
      //{"currency", "USD"},
      //{"value", 42.99}
    //}}
  //};

}

