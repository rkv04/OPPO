#include "sea.hpp"

#include <iostream>

void Sea::print(std::ostream &ost) {
    ost << this->title << " " << this->depth << " " << this->salinity << std::endl;
}

void Sea::loadFromStream(std::istream &ist) {
    std::string title;
    float depth, salinity;
    ist >> title >> depth >> salinity;
    this->title = title;
    this->depth = depth;
    this->salinity = salinity;
}