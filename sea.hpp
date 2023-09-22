#ifndef SEA_HPP
#define SEA_HPP

#include <string>

class Sea {
public:
    Sea(std::string sea_title, float sea_depth, float sea_salinity);
    void print(std::ostream &ost);
private:
    std::string title;
    float depth;
    float salinity;
};

#endif // SEA_HPP