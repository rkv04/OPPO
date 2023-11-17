#include "sea.hpp"
#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <clocale>
#include <cctype>

Sea::Sea(const std::vector<std::string> &data) {
    if (data.size() < 3) throw std::runtime_error("Too few values");
    std::vector<std::string>::const_iterator iter = data.begin();
    std::string title = *iter;
    float depth = strToFloat(*(iter+=1));
    float salinity = strToFloat(*(iter+=1));
    Sea::validateData(title, depth, salinity);
    this->title = title;
    this->depth = depth;
    this->salinity = salinity;
    this->fish = Fish::createFishes(iter+=1, data.end());
}

Sea::~Sea() {
    for (auto i : this->fish) {
        delete i;
    }
}

void Sea::validateTitle(const std::string title) {
    for (char c : title) {
        if (RUS_ALPH.find(c) == std::string::npos && !isalpha(c) && c != ' ' && c != '-') throw std::runtime_error("Invalid sea title");
    }
}

void Sea::validateDepth(const float depth) {
    if (depth <= 0) throw std::runtime_error("Invalid depth");
}

void Sea::validateSalinity(const float salinity) {
    if (salinity > 1 || salinity < 0) throw std::runtime_error("Invalid salinity");
}

void Sea::validateData(const std::string title, const float depth, const float salinity) {
    Sea::validateTitle(title);
    Sea::validateDepth(depth);
    Sea::validateSalinity(salinity);
}

void Sea::print(std::ostream &ost) {
    ost << this->title << " " << this->depth << " " << this->salinity << " ";
    for (auto fish : this->fish) {
        fish->print(ost);
    }
    ost << std::endl;
}