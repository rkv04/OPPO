#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
#include <sstream>
#include <algorithm>

#include "fish.hpp"
#include "sea.hpp"
#include "utils.hpp"

namespace seas {
    void print(const std::vector<Sea*> &seas) {
        std::string sep = "---------------------------------";
        std::cout << sep << std::endl;
        for (auto sea : seas) {
            sea->print(std::cout);
        }
        std::cout << sep << std::endl;
    }

    void del(const std::vector<Sea*> &seas) {
        for (auto sea : seas) {
            delete sea;
        }
    }

    void readFromFile(std::istream &ist, std::vector<Sea*> &seas) {
        size_t num_line = 0;
        while (!ist.eof() && !ist.fail()) {
            num_line += 1;
            std::string line;
            getline(ist, line);
            std::vector<std::string> data;
            try {
                parseLine(line, data, ' ');
                Sea* new_sea = new Sea(data);
                seas.push_back(new_sea);
            }
            catch(const std::runtime_error& ex) {
                std::cout << ex.what() << " in line " << num_line << std::endl;
            }
            catch(const std::invalid_argument& ex) {
                std::cout << "Data type error in line " << num_line << std::endl;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<Sea*> seas;
    std::ifstream ist("./seas.txt");
    if (!ist.is_open()) {
        std::cout << "--file opening error--" << std::endl;
        return -1;
    }
    seas::readFromFile(ist, seas);
    seas::print(seas);
    seas::del(seas);
    return 0;
}