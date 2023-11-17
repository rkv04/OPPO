#ifndef FISH_HPP
#define FISH_HPP

#include <string>
#include <vector>

class Fish {
public:
    Fish(std::string title);
    void print(std::ostream &ist);
    static void validateTitle(std::string title);
    static std::vector<Fish*> createFishes(std::vector<std::string>::const_iterator it_beg, std::vector<std::string>::const_iterator it_end);
private:
    std::string title;
};

#endif // FISH_HPP