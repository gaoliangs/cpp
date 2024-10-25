#include "output.h"
#include <fstream>
#include <numeric>
#include "func.h"
#include "symbol.h"
#include "symbolic.h"
#include <iostream>
#include <unordered_map>


void writeFormulaToCppFile(const std::string& filename, const std::vector<std::string>& data,
                           int n_edge, int n_leaf, const std::vector<int>& smloc,
                           const std::vector<int>& gmloc, bool isTrivial) {
    std::ofstream file(filename);
    std::vector<Symbol> t = createSymbols('t', n_edge + 1);
    std::vector<Symbol> c = createSymbols('c', n_edge + 1);
    std::vector<Symbol> tl = createSymbols("tl", n_leaf + 1);

    file << "#include <vector>\n";
    file << "#include \"symbolic.h\"\n\n";
    file << "std::vector<SymbolicExpression> " << (isTrivial ? "la" : "l") << ";\n\n";
    file << "void calculate_" << (isTrivial ? "la" : "l") << "() {\n";

    for (size_t i = 0; i < data.size(); ++i) {
        
        std::unordered_map<std::string, std::vector<std::string>> memo;
        Indices idx(0, 1);

        auto f = recursive_split(data[i], idx, memo);

        SymbolicExpression fx = SymbolicExpression(f[0]) + SymbolicExpression(f[3]);

        file << "    " << (isTrivial ? "la" : "l") << ".push_back(" << fx.toString() << ");\n";
    }

    file << "}\n";
    file.close();
}


void writeVariablesToCppFile(const std::string& filename, const std::vector<Symbol>& t,
                             const std::vector<Symbol>& c, const std::vector<int>& gmloc) {
    std::ofstream file(filename);
    file << "#include <vector>\n";
    file << "#include \"symbolic.h\"\n\n";

    file << "SymbolicExpression sumlambda;\n";
    file << "std::vector<SymbolicExpression> l;\n";
    file << "std::vector<SymbolicExpression> la;\n\n";

    file << "void initialize_variables(const std::vector<double>& x_values) {\n";

    for (size_t i = 1; i < t.size(); ++i) {
        file << "    SymbolicExpression " << t[i].getName() << " = x_values[" << i - 1 << "];\n";
    }
    for (size_t j = 0; j < gmloc.size(); ++j) {
        file << "    SymbolicExpression tl" << gmloc[j] << " = x_values[" << j + t.size() - 1 << "];\n";
    }
    for (size_t k = 1; k < c.size(); ++k) {
        file << "    SymbolicExpression " << c[k].getName() << " = x_values[" << k + t.size() + gmloc.size() - 2 << "];\n";
    }
    file << "}\n";
    file.close();
}


void writeVariablesToCppFileNoC(const std::string& filename, const std::vector<Symbol>& t,
                                const std::vector<int>& gmloc) {
    std::ofstream file(filename);
    file << "#include <vector>\n";
    file << "#include \"symbolic.h\"\n\n";

    file << "SymbolicExpression sumlambda;\n";
    file << "std::vector<SymbolicExpression> l;\n";
    file << "std::vector<SymbolicExpression> la;\n\n";

    file << "void initialize_variables(const std::vector<double>& x_values) {\n";

    for (size_t i = 1; i < t.size(); ++i) {
        file << "    SymbolicExpression " << t[i].getName() << " = x_values[" << i - 1 << "];\n";
    }
    for (size_t j = 0; j < gmloc.size(); ++j) {
        file << "    SymbolicExpression tl" << gmloc[j] << " = x_values[" << j + t.size() - 1 << "];\n";
    }
    
    for (size_t k = 1; k < t.size(); ++k) {
        file << "    SymbolicExpression c" << k << " = 0;\n";
    }
    file << "}\n";
    file.close();
}


void writeTreeScoreCppFile(const std::string& filename, int n_edge, int gm_size,
                           const SymbolicExpression& sumlambda, bool includeC) {
    std::ofstream file(filename);
    file << "#include <iostream>\n";
    file << "#include <vector>\n";
    file << "#include \"optimizer.h\"\n";
    file << "#include \"variables.h\"\n";
    file << "#include \"lambda_formula.h\"\n";
    file << "#include \"lambda_formula_trivial.h\"\n\n";

    file << "int main() {\n";
    int n_vars = n_edge + gm_size;
    if (includeC) {
        n_vars += n_edge;
    }
    file << "    int n_vars = " << n_vars << ";\n";
    file << "    std::vector<double> x0(n_vars, 1.0);\n";
    file << "    std::vector<double> lb(n_vars, 0.0);\n";
    if (includeC) {
        file << "    for (int i = " << n_edge + gm_size << "; i < n_vars; ++i) lb[i] = -10;\n";
    }
    file << "    std::vector<double> ub(n_vars, 1.0);\n";
    if (includeC) {
        file << "    for (int i = " << n_edge + gm_size << "; i < n_vars; ++i) ub[i] = 10;\n";
    }
    file << "\n";

    file << "    Optimizer optimizer;\n";
    file << "    std::vector<double> x_optimal;\n";
    file << "    double fval;\n";
    file << "    optimizer.optimize(x0, lb, ub, x_optimal, fval);\n\n";

    file << "    std::cout << \"Optimal solution:\" << std::endl;\n";
    file << "    for (size_t i = 0; i < x_optimal.size(); ++i) {\n";
    file << "        std::cout << \"x[\" << i + 1 << \"] = \" << x_optimal[i] << std::endl;\n";
    file << "    }\n";
    file << "    std::cout << \"Optimal objective function value: \" << fval << std::endl;\n";
    file << "    return 0;\n";
    file << "}\n";
    file.close();
}


void generateCppFiles(const std::vector<std::string>& markerdata, const std::vector<std::string>& trivialtopo,
                      int n_edge, int n_leaf, const std::vector<int>& smloc, const std::vector<int>& gmloc,
                      const std::vector<Symbol>& t, const std::vector<Symbol>& c, const std::vector<Symbol>& tl,
                      const SymbolicExpression& sumlambda, bool includeC) {
    
    writeFormulaToCppFile("lambda_formula.cpp", markerdata, n_edge, n_leaf, smloc, gmloc, false);
    writeFormulaToCppFile("lambda_formula_trivial.cpp", trivialtopo, n_edge, n_leaf, smloc, gmloc, true);

    
    if (includeC) {
        writeVariablesToCppFile("variables.cpp", t, c, gmloc);
    } else {
        writeVariablesToCppFileNoC("variables.cpp", t, gmloc);
    }

   
    writeTreeScoreCppFile("treescore.cpp", n_edge, static_cast<int>(gmloc.size()), sumlambda, includeC);
}
