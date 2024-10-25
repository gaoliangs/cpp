#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include "symbol.h"
#include "symbolic.h"
#include "matrix.h"


struct Indices {
    int edge_num;
    int leaf_index;

    Indices(int edge = 0, int leaf = 1) : edge_num(edge), leaf_index(leaf) {}
};


std::vector<std::string> recursive_split(const std::string& s, Indices& idx,
                                         std::unordered_map<std::string, std::vector<std::string>>& memo);

std::vector<std::vector<std::string>> findsplit(const std::string& s);
Matrix combine(const std::vector<Matrix>& matrices);
Matrix multiplyMatrices(const Matrix& a, const Matrix& b);


bool all(const std::vector<SymbolicExpression>& vec, const std::string& value);
SymbolicExpression reduce(const std::vector<SymbolicExpression>& vec,
                          const std::function<SymbolicExpression(const SymbolicExpression&, const SymbolicExpression&)>& func);

#endif // FUNC_H
