#include "data.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            if (cell == "B") cell = "01";
            row.push_back(cell);
        }

        data.push_back(row);
    }

    return data;
}

std::pair<std::vector<std::string>, std::vector<std::string>> classifyTaxa(const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& data) {
    std::vector<std::string> singletaxa, grouptaxa;
    for (size_t col = 0; col < taxaname.size(); ++col) {
        bool hasB = false;
        for (size_t row = 1; row < data.size(); ++row) {
            if (data[row][col] == "01") {
                hasB = true;
                break;
            }
        }
        if (hasB) {
            grouptaxa.push_back(taxaname[col]);
        } else {
            singletaxa.push_back(taxaname[col]);
        }
    }
    return {singletaxa, grouptaxa};
}
