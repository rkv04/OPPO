#ifndef SEA_HPP
#define SEA_HPP

#include <string>

class Sea {
public:
    void print(std::ostream &ost);
    void loadFromStream(std::istream &ist);
private:
    std::string title;
    float depth;
    float salinity;
};

#endif // SEA_HPP