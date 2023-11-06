#include "Constants.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;


std::string getPath(const std::string& path) {
    return constants::gResPath + path;
}


int main(int argc, char* argv[]) {
    std::ifstream f(getPath("json/config.json"));
    json data = json::parse(f);

    data["player"]["hp"] = 100;

    std::ofstream o(getPath("json/config.json"));
    o << data.dump() << std::endl;
    std::cout << data.dump() << std::endl;
}