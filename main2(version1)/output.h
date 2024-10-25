#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>
#include "symbol.h"
#include "symbolic.h"


void writeTreeScoreToFile(const std::string& filename, int n_edge, int gm_size, const SymbolicExpression& sumlambda);
void writeTreeScoreToFileNoC(const std::string& filename, int n_edge, int gm_size, const SymbolicExpression& sumlambda);


void writeLambdaFormulaCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<std::string>& data);
void writeLambdaFormulaTrivialCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<std::string>& data);
void writeVariablesCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<Symbol>& t, const std::vector<Symbol>& c, const std::vector<int>& gmloc);

#endif
