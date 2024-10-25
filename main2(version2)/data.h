#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

std::vector<std::vector<std::string>> readCSV(const std::string& filename);
std::pair<std::vector<std::string>, std::vector<std::string>> classifyTaxa(const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& data);

#endif
