#ifndef SEA_HPP
#define SEA_HPP

#include "fish.hpp"

#include <string>
#include <vector>

class Sea {
public:
    Sea(const std::vector<std::string> &data);
    ~Sea();
    void print(std::ostream &ost);
    static void validateData(const std::string title, const float depth, const float salinity);
    static void validateTitle(const std::string title);
    static void validateDepth(const float depth);
    static void validateSalinity(const float salinity);
private:
    std::string title;
    float depth;
    float salinity;
    std::vector<Fish*> fish;
};

#endif // SEA_HPP