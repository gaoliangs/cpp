#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <string>
#include "matrix.h"
#include "symbol.h"

std::vector<std::vector<std::string>> findsplit(const std::string& s, std::vector<int>& edge_index, std::vector<int>& taxa_index);
Matrix combine(const std::vector<Matrix>& vector);
Matrix recursive_split(const std::string& s, std::vector<int>& edge_num, std::vector<int>& leaf_index, 
                       const std::vector<int>& smloc, const std::vector<Symbol>& t, const std::vector<Symbol>& c, 
                       const std::vector<Symbol>& tl);
Matrix multiplyMatrices(const Matrix& a, const Matrix& b);

#endif
