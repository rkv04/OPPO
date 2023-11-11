#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

float strToFloat(std::string str) {
    size_t count_chars_processed = 0;
    float num_f = std::stof(str, &count_chars_processed);
    if (count_chars_processed != str.length()) {
        throw std::invalid_argument("Data type error: \"" + str + '\"');
    }
    return num_f;
}

void parseLine(const std::string &line, std::vector<std::string> &results, const char sep) {
    std::stringstream srcStream(line);
    std::string value;
    std::string part;
    bool inQuotes = false;
    while (std::getline(srcStream, value, sep)) {
        while (std::count(value.begin(), value.end(), '\"') % 2 != 0) {
            inQuotes = true;
            if (!std::getline(srcStream, part, sep)) throw std::runtime_error("No closing quote");
            value = value + sep + part;
        }
        if (inQuotes) {
            value = value.substr(1, value.size() - 2);
        }
        if (value.empty()) continue;
        results.push_back(value);
        inQuotes = false;
    }
}