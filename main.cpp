#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;

class Sea {
public:
    Sea(string sea_title, float sea_depth, float sea_salinity) : title{sea_title}, depth{sea_depth}, salinity{sea_salinity}
    {
    }
    void print(ostream &ost) {
        ost << this->title << " " << this->depth << " " << this->salinity << endl;
    }
private:
    string title;
    float depth;
    float salinity;
};

Sea* getSea(std::ifstream &ist) {
    string title;
    float depth, salinity;
    ist >> title >> depth >> salinity;
    Sea *newSea = new Sea(title, depth, salinity);
    return newSea;
}

void printSeas(const vector<Sea*> &seas) {
    for (auto sea : seas) {
        sea->print(std::cout);
    }
}

void deleteSeas(vector<Sea*> &seas) {
    for (auto i : seas) {
        delete i;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<Sea*> seas;
    ifstream ist("seas.txt");
    while (!ist.eof()) {
        Sea *newSea = getSea(ist);
        seas.push_back(newSea);
    }
    ist.close();
    printSeas(seas);
    deleteSeas(seas);
    return 0;
}