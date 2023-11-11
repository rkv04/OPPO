#ifndef FISH_HPP
#define FISH_HPP

#include <string>

class Fish {
public:
    Fish(std::string title);
    void setTitle(std::string title);
    void print(std::ostream &ist);
private:
    std::string title;
};

#endif // FISH_HPP