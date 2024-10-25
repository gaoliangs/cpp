#include "util.h"
#include <algorithm>
#include <regex>
#include <sstream>

std::vector<int> getIndices(const std::vector<std::string>& container, const std::vector<std::string>& items) {
    std::vector<int> indices;
    for (const auto& item : items) {
        auto it = std::find(container.begin(), container.end(), item);
        if (it != container.end()) {
            indices.push_back(std::distance(container.begin(), it) + 1); // +1 to match Python's 1-based indexing
        }
    }
    return indices;
}

int countOccurrences(const std::string& str, char ch) {
    return std::count(str.begin(), str.end(), ch);
}

std::vector<std::string> splitTopo(const std::string& topo) {
    std::string cleaned = std::regex_replace(topo, std::regex("[()]"), "");
    std::vector<std::string> result;
    std::istringstream ss(cleaned);
    std::string item;
    while (std::getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}
