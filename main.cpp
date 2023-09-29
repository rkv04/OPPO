#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <clocale>

#include "sea.hpp"

namespace seas {
    void print(const std::vector<Sea*> &seas) {
        for (auto sea : seas) {
            sea->print(std::cout);
        }
    }

    void del(const std::vector<Sea*> &seas) {
        for (auto i : seas) {
            delete i;
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<Sea*> seas;
    std::ifstream ist("seas.txt");
    while (!ist.eof()) {
        Sea *new_sea = new Sea();
        new_sea->loadFromStream(ist);
        seas.push_back(new_sea);
    }
    ist.close();
    seas::print(seas);
    seas::del(seas);
    return 0;
}