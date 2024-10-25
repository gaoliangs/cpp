#ifndef SYMBOLIC_H
#define SYMBOLIC_H

#include <string>
#include <vector>
#include "symbol.h"

class SymbolicExpression {
public:
    SymbolicExpression(const std::string& expr);
    std::string toString() const;
    SymbolicExpression operator+(const SymbolicExpression& other) const;
    SymbolicExpression operator*(const SymbolicExpression& other) const;
    SymbolicExpression operator-(const SymbolicExpression& other) const;
    SymbolicExpression operator/(const SymbolicExpression& other) const;

private:
    std::string expression;
};

SymbolicExpression calculateSumLambda(const std::vector<Symbol>& t, const std::vector<Symbol>& c, int n_leaf);
SymbolicExpression exp(const SymbolicExpression& expr);
SymbolicExpression log(const SymbolicExpression& expr);

#endif
