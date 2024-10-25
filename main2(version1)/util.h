#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>

std::vector<int> getIndices(const std::vector<std::string>& container, const std::vector<std::string>& items);
int countOccurrences(const std::string& str, char ch);
std::vector<std::string> splitTopo(const std::string& topo);

#endif
