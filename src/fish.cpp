#include "fish.hpp"
#include "utils.hpp"

#include <iostream>

Fish::Fish(std::string title) {
    Fish::validateTitle(title);
    this->title = title;
}

void Fish::validateTitle(std::string title) {
    for (char c : title) {
        if (RUS_ALPH.find(c) == std::string::npos && !isalpha(c) && c != ' ' && c != '-') throw std::runtime_error("Invalid fish title");
    }
}

void Fish::print(std::ostream &ost) {
    ost << this->title << " ";
}

std::vector<Fish*> Fish::createFishes(std::vector<std::string>::const_iterator it_beg, std::vector<std::string>::const_iterator it_end) {
    std::vector<Fish*> vec_fish;
    for (auto it = it_beg; it != it_end; it++) {
        Fish *new_fish = new Fish(*it);
        vec_fish.push_back(new_fish);
    }
    return vec_fish;
}