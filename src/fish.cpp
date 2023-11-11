#include "fish.hpp"

#include <iostream>

Fish::Fish(std::string title) {
    
    this->setTitle(title);
}

void Fish::print(std::ostream &ost) {
    ost << this->title << " ";
}

void Fish::setTitle(std::string title) {
    this->title = title;
}