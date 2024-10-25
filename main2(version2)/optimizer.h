#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>

class Optimizer {
public:
    void optimize(const std::vector<double>& x0, const std::vector<double>& lb,
                  const std::vector<double>& ub, std::vector<double>& x_optimal,
                  double& fval);
};

#endif // OPTIMIZER_H
