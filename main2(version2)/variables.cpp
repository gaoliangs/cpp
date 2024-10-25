#include <vector>
#include "symbolic.h"

SymbolicExpression sumlambda;
std::vector<SymbolicExpression> l;
std::vector<SymbolicExpression> la;

void initialize_variables(const std::vector<double>& x_values) {
    SymbolicExpression t1 = x_values[0];
    SymbolicExpression t2 = x_values[1];
    SymbolicExpression t3 = x_values[2];
    SymbolicExpression tl2 = x_values[3];
    SymbolicExpression tl5 = x_values[4];
    SymbolicExpression tl3 = x_values[5];
    SymbolicExpression c1 = x_values[6];
    SymbolicExpression c2 = x_values[7];
    SymbolicExpression c3 = x_values[8];
}
