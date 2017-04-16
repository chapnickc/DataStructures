#include "json.hpp"

using json = nlohmann::json;
//using nlohmann::json;

namespace ns {
    void to_json(json& j, const person& p) {
        j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const json& j, person& p) {
        p.name = j.at("name").get<std::string>();
        p.address = j.at("address").get<std::string>();
        p.age = j.at("age").get<int>();
    }
}
