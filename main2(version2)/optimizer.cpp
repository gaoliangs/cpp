#include "optimizer.h"
#include <functional>
#include "symbolic.h"
#include "variables.h"
#include "lambda_formula.h"
#include "lambda_formula_trivial.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


void Optimizer::optimize(const std::vector<double>& x0, const std::vector<double>& lb,
                         const std::vector<double>& ub, std::vector<double>& x_optimal,
                         double& fval) {
    const int max_iter = 10000;
    const double tol = 1e-6;
    const double alpha_init = 0.1;
    const double beta = 0.5;       
    const double c = 1e-4;         

    x_optimal = x0;
    fval = objectiveFunction(x_optimal);
    int n = x0.size();

    for (int iter = 0; iter < max_iter; ++iter) {
        
        std::vector<double> grad(n, 0.0);
        double h = 1e-8; 

        for (int i = 0; i < n; ++i) {
            std::vector<double> x_plus = x_optimal;
            x_plus[i] += h;
            double f_plus = objectiveFunction(x_plus);
            grad[i] = (f_plus - fval) / h;
        }

       
        double grad_norm = std::sqrt(std::inner_product(grad.begin(), grad.end(), grad.begin(), 0.0));
        if (grad_norm < tol) {
            break;
        }

       
        double alpha = alpha_init;
        std::vector<double> x_new(n);
        while (true) {
            
            for (int i = 0; i < n; ++i) {
                x_new[i] = x_optimal[i] - alpha * grad[i];
                
                x_new[i] = std::max(lb[i], std::min(ub[i], x_new[i]));
            }

            double f_new = objectiveFunction(x_new);

           
            double armijo = fval - c * alpha * grad_norm * grad_norm;
            if (f_new <= armijo) {
                fval = f_new;
                x_optimal = x_new;
                break;
            } else {
                alpha *= beta;
            }

           
            if (alpha < 1e-8) {
                std::cerr << "Line search failed." << std::endl;
                break;
            }
        }
    }
}


double objectiveFunction(const std::vector<double>& x_values) {
    
    initialize_variables(x_values);

    
    sumlambda = calculateSumLambda();

    
    calculate_l();
    calculate_la();

    
    double F = 0.0;
    for (const auto& li : l) {
        double li_value = li.evaluate();
        if (li_value <= 0) {
            li_value = 1e-8;
        }
        F += std::log(li_value);
    }

    double suml_value = sumlambda.evaluate();
    if (suml_value <= 0) {
        suml_value = 1e-8; 
    }
    F -= l.size() * std::log(suml_value);

    return -F; 
}
