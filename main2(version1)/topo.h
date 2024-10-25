#ifndef TOPO_H
#define TOPO_H

#include <vector>
#include <string>

std::vector<std::string> generateMarkerData(const std::string& topo, const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& taxadata);
std::vector<std::vector<std::string>> generateTrivialMarker(int taxanum, const std::vector<int>& gm);
std::vector<std::string> generateTrivialTopo(const std::string& topo, const std::vector<std::string>& taxaname, const std::vector<std::vector<std::string>>& trivial_marker);

#endif
