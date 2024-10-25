#include "symbolic.h"
#include <sstream>
#include <cmath>

SymbolicExpression::SymbolicExpression(const std::string& expr) : expression(expr) {}

std::string SymbolicExpression::toString() const {
    return expression;
}

SymbolicExpression SymbolicExpression::operator+(const SymbolicExpression& other) const {
    if (expression == "0") return other;
    if (other.expression == "0") return *this;
    return SymbolicExpression("(" + expression + " + " + other.expression + ")");
}

SymbolicExpression SymbolicExpression::operator*(const SymbolicExpression& other) const {
    if (expression == "0" || other.expression == "0") return SymbolicExpression("0");
    if (expression == "1") return other;
    if (other.expression == "1") return *this;
    return SymbolicExpression("(" + expression + " * " + other.expression + ")");
}

SymbolicExpression SymbolicExpression::operator-(const SymbolicExpression& other) const {
    if (other.expression == "0") return *this;
    return SymbolicExpression("(" + expression + " - " + other.expression + ")");
}

SymbolicExpression SymbolicExpression::operator/(const SymbolicExpression& other) const {
    if (other.expression == "1") return *this;
    return SymbolicExpression("(" + expression + " / " + other.expression + ")");
}

SymbolicExpression calculateSumLambda(const std::vector<Symbol>& t, const std::vector<Symbol>& c, int n_leaf) {
    std::ostringstream oss;
    oss << "1";
    for (int i = 1; i < n_leaf - 1; ++i) {
        oss << "-exp(" << c[i].getName() << ")*log(" << t[i].getName() << ")";
    }
    return SymbolicExpression(oss.str());
}

SymbolicExpression exp(const SymbolicExpression& expr) {
    return SymbolicExpression("exp(" + expr.toString() + ")");
}

SymbolicExpression log(const SymbolicExpression& expr) {
    return SymbolicExpression("log(" + expr.toString() + ")");
}
