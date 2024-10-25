#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>
#include "symbol.h"
#include "symbolic.h"

void writeFormulaToCppFile(const std::string& filename, const std::vector<std::string>& data,
                           int n_edge, int n_leaf, const std::vector<int>& smloc,
                           const std::vector<int>& gmloc, bool isTrivial = false);

void writeVariablesToCppFile(const std::string& filename, const std::vector<Symbol>& t,
                             const std::vector<Symbol>& c, const std::vector<int>& gmloc);

void writeVariablesToCppFileNoC(const std::string& filename, const std::vector<Symbol>& t,
                                const std::vector<int>& gmloc);

void writeTreeScoreCppFile(const std::string& filename, int n_edge, int gm_size,
                           const SymbolicExpression& sumlambda, bool includeC);

void generateCppFiles(const std::vector<std::string>& markerdata,
                      const std::vector<std::string>& trivialtopo, int n_edge, int n_leaf,
                      const std::vector<int>& smloc, const std::vector<int>& gmloc,
                      const std::vector<Symbol>& t, const std::vector<Symbol>& c,
                      const std::vector<Symbol>& tl, const SymbolicExpression& sumlambda,
                      bool includeC);

#endif // OUTPUT_H
