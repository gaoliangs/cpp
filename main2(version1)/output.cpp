#include "output.h"
#include <fstream>
#include <numeric>
#include <algorithm>
#include "func.h"

void writeTreeScoreToFile(const std::string& filename, int n_edge, int gm_size, const SymbolicExpression& sumlambda) {
    std::ofstream file(filename);
    file << "function [F] = treescore()\nclear all\n\nobjective = @(x) myObjective(x);\n";
    file << "x0 = ones(1," << n_edge * 2 + gm_size << ");\n";
    file << "lb = [zeros(1," << n_edge + gm_size << "),ones(1," << n_edge << ")*-10];\n";
    file << "ub = [ones(1," << n_edge + gm_size << "),ones(1," << n_edge << ")*10];\n\n";
    file << "options = optimoptions('fmincon', 'Display', 'off','MaxFunctionEvaluations',50000,'MaxIterations',10000);\n";
    file << "[x_optimal,fval,exitflag] = fmincon(objective, x0, [], [], [], [], lb, ub, [], options);\n\n";
    file << "disp('Optimal solution t:');\ndisp(-log(x_optimal(1:" << n_edge + gm_size << ")));\n";
    file << "disp('Optimal solution c:');\ndisp(exp(x_optimal(" << 1 + n_edge + gm_size << ":" << n_edge + n_edge + gm_size << ")));\n";
    file << "disp('Optimal objective function value:');\ndisp(exp(vpa(-fval)));\n";
    file << "F= -fval;\n\nend\n\n";
    file << "function result = myObjective(x)\n\tvariables\n\tlambda_formula\n\tlambda_formula_trivial\n\t";
    file << "suml=" << sumlambda.toString() << "-sum(la);\n\t";
    file << "F = sum(log(l))-length(l)*log(suml);\n\tresult = -F;\nend\n";
    file.close();
}

void writeTreeScoreToFileNoC(const std::string& filename, int n_edge, int gm_size, const SymbolicExpression& sumlambda) {
    std::ofstream file(filename);
    file << "function [F] = treescore()\nclear all\n\nobjective = @(x) myObjective(x);\n";
    file << "x0 = ones(1," << n_edge + gm_size << ");\n";
    file << "lb = zeros(1," << n_edge + gm_size << ");\n";
    file << "ub = ones(1," << n_edge + gm_size << ");\n\n";
    file << "options = optimoptions('fmincon', 'Display', 'off','MaxFunctionEvaluations',50000,'MaxIterations',10000);\n";
    file << "[x_optimal,fval,exitflag] = fmincon(objective, x0, [], [], [], [], lb, ub, [], options);\n\n";
    file << "disp('Optimal solution:');\ndisp(-log(x_optimal(1:" << n_edge + gm_size << ")));\n";
    file << "disp('Optimal objective function value:');\ndisp(exp(vpa(-fval)));\n";
    file << "F= -fval;\n\nend\n\n";
    file << "function result = myObjective(x)\n\tvariables\n\tlambda_formula\n\tlambda_formula_trivial\n\t";
    file << "suml=" << sumlambda.toString() << "-sum(la);\n\t";
    file << "F = sum(log(l))-length(l)*log(suml);\n\tresult = -F;\nend\n";
    file.close();
}

void writeLambdaFormulaCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<std::string>& data) {
    std::ofstream h_file(h_filename);
    std::string guard = h_filename.substr(0, h_filename.find('.')) + "_H";
    std::transform(guard.begin(), guard.end(), guard.begin(), ::toupper);
    h_file << "#ifndef " << guard << "\n";
    h_file << "#define " << guard << "\n\n";
    h_file << "#include <vector>\n#include <string>\n\n";
    h_file << "std::vector<std::string> getLambdaFormula();\n\n";
    h_file << "#endif // " << guard << "\n";
    h_file.close();

    std::ofstream cpp_file(cpp_filename);
    cpp_file << "#include \"" << h_filename << "\"\n\n";
    cpp_file << "std::vector<std::string> getLambdaFormula() {\n";
    cpp_file << "    return {\n";
    for (size_t i = 0; i < data.size(); ++i) {
        cpp_file << "        \"" << data[i] << "\"";
        if (i != data.size() - 1) cpp_file << ",";
        cpp_file << "\n";
    }
    cpp_file << "    };\n";
    cpp_file << "}\n";
    cpp_file.close();
}

void writeLambdaFormulaTrivialCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<std::string>& data) {
    std::ofstream h_file(h_filename);
    std::string guard = h_filename.substr(0, h_filename.find('.')) + "_H";
    std::transform(guard.begin(), guard.end(), guard.begin(), ::toupper);
    h_file << "#ifndef " << guard << "\n";
    h_file << "#define " << guard << "\n\n";
    h_file << "#include <vector>\n#include <string>\n\n";
    h_file << "std::vector<std::string> getLambdaFormulaTrivial();\n\n";
    h_file << "#endif // " << guard << "\n";
    h_file.close();

    std::ofstream cpp_file(cpp_filename);
    cpp_file << "#include \"" << h_filename << "\"\n\n";
    cpp_file << "std::vector<std::string> getLambdaFormulaTrivial() {\n";
    cpp_file << "    return {\n";
    for (size_t i = 0; i < data.size(); ++i) {
        cpp_file << "        \"" << data[i] << "\"";
        if (i != data.size() - 1) cpp_file << ",";
        cpp_file << "\n";
    }
    cpp_file << "    };\n";
    cpp_file << "}\n";
    cpp_file.close();
}

void writeVariablesCpp(const std::string& cpp_filename, const std::string& h_filename, const std::vector<Symbol>& t, const std::vector<Symbol>& c, const std::vector<int>& gmloc) {
    std::ofstream h_file(h_filename);
    std::string guard = h_filename.substr(0, h_filename.find('.')) + "_H";
    std::transform(guard.begin(), guard.end(), guard.begin(), ::toupper);
    h_file << "#ifndef " << guard << "\n";
    h_file << "#define " << guard << "\n\n";
    h_file << "#include <vector>\n#include <string>\n\n";
    h_file << "struct Variables {\n";
    h_file << "    std::vector<double> t;\n";
    h_file << "    std::vector<double> c;\n";
    h_file << "    std::vector<double> tl;\n";
    h_file << "};\n\n";
    h_file << "Variables getVariables();\n\n";
    h_file << "#endif // " << guard << "\n";
    h_file.close();

    std::ofstream cpp_file(cpp_filename);
    cpp_file << "#include \"" << h_filename << "\"\n\n";
    cpp_file << "Variables getVariables() {\n";
    cpp_file << "    Variables vars;\n\n";
    cpp_file << "    vars.t = {";
    for (size_t i = 0; i < t.size(); ++i) {
        cpp_file << t[i].getName();
        if (i != t.size() - 1) cpp_file << ", ";
    }
    cpp_file << "};\n";
    cpp_file << "    vars.c = {";
    for (size_t i = 0; i < c.size(); ++i) {
        cpp_file << c[i].getName();
        if (i != c.size() - 1) cpp_file << ", ";
    }
    cpp_file << "};\n";
    cpp_file << "    vars.tl = {";
    for (size_t i = 0; i < gmloc.size(); ++i) {
        cpp_file << "tl" << gmloc[i];
        if (i != gmloc.size() - 1) cpp_file << ", ";
    }
    cpp_file << "};\n\n";
    cpp_file << "    return vars;\n";
    cpp_file << "}\n";
    cpp_file.close();
}
