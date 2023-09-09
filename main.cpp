#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Sea {
    std::string title;
    float depth;
    float salinity;
};

int main() {
    std::ifstream ist("seas.txt");
    std::vector<Sea> seas;
    while (!ist.eof()) {
        Sea newSea;
        ist >> newSea.title >> newSea.depth >> newSea.salinity;
        seas.push_back(newSea);
    }
    ist.close();
    for (int i = 0; i < seas.size(); i++) {
        std::cout << seas[i].title << " " << seas[i].depth << " " << seas[i].salinity << std::endl;
    }
    return 0;
}