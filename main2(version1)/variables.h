#ifndef VARIABLES_H
#define VARIABLES_H

#include <vector>
#include <string>

struct Variables {
    std::vector<double> t;
    std::vector<double> c;
    std::vector<double> tl;
};

Variables getVariables();

#endif // VARIABLES_H
