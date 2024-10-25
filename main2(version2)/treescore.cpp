#include <iostream>
#include <vector>
#include "optimizer.h"
#include "variables.h"
#include "lambda_formula.h"
#include "lambda_formula_trivial.h"

int main() {
    int n_vars = 9;
    std::vector<double> x0(n_vars, 1.0);
    std::vector<double> lb(n_vars, 0.0);
    for (int i = 6; i < n_vars; ++i) lb[i] = -10;
    std::vector<double> ub(n_vars, 1.0);
    for (int i = 6; i < n_vars; ++i) ub[i] = 10;

    Optimizer optimizer;
    std::vector<double> x_optimal;
    double fval;
    optimizer.optimize(x0, lb, ub, x_optimal, fval);

    std::cout << "Optimal solution:" << std::endl;
    for (size_t i = 0; i < x_optimal.size(); ++i) {
        std::cout << "x[" << i + 1 << "] = " << x_optimal[i] << std::endl;
    }
    std::cout << "Optimal objective function value: " << fval << std::endl;
    return 0;
}
