#include "sea.hpp"

#include <iostream>

Sea::Sea(std::string sea_title, float sea_depth, float sea_salinity) : title{sea_title}, depth{sea_depth}, salinity{sea_salinity}
{
}

void Sea::print(std::ostream &ost) {
    ost << this->title << " " << this->depth << " " << this->salinity << std::endl;
}