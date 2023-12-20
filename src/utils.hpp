#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

inline const std::string RUS_ALPH = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
void parseLine(const std::string &line, std::vector<std::string> &results, const char sep);
float strToFloat(std::string value);

#endif // UTILS_HPP