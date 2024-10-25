#include "topo.h"
#include <regex>
#include <algorithm>

std::vector<std::string> generateMarkerData(const std::string& topo, const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& taxadata) {
    std::vector<std::string> markerdata;
    for (const auto& mi : taxadata) {
        std::string original = topo;
        for (size_t i = 0; i < taxaname.size(); ++i) {
            std::regex pattern("\\b" + taxaname[i] + "\\b");
            original = std::regex_replace(original, pattern, mi[i], std::regex_constants::format_first_only);
        }
        markerdata.push_back(original);
    }
    return markerdata;
}

std::vector<std::vector<std::string>> generateTrivialMarker(int taxanum, const std::vector<int>& gm) {
    std::vector<std::vector<std::string>> lists;
    
    lists.push_back(std::vector<std::string>(taxanum, "0"));
    lists.push_back(std::vector<std::string>(taxanum, "1"));
    
    for (int i = 0; i < taxanum; ++i) {
        std::vector<std::string> current_list(taxanum, "0");
        current_list[i] = "1";
        lists.push_back(current_list);
    }
    
    for (int gm_index : gm) {
        std::vector<std::string> current_list(taxanum, "0");
        current_list[gm_index - 1] = "01";
        lists.push_back(current_list);
    }
    
    return lists;
}

std::vector<std::string> generateTrivialTopo(const std::string& topo, const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& trivial_marker) {
    std::vector<std::string> trivialtopo;
    for (const auto& ti : trivial_marker) {
        std::string tritopo = topo;
        for (size_t j = 0; j < taxaname.size(); ++j) {
            std::regex pattern("\\b" + taxaname[j] + "\\b");
            tritopo = std::regex_replace(tritopo, pattern, ti[j], std::regex_constants::format_first_only);
        }
        trivialtopo.push_back(tritopo);
    }
    return trivialtopo;
}
