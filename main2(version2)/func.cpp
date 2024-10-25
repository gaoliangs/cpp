#include "func.h"
#include <stack>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>


bool all(const std::vector<SymbolicExpression>& vec, const std::string& value) {
    return std::all_of(vec.begin(), vec.end(), [&value](const SymbolicExpression& expr) { return expr.toString() == value; });
}

SymbolicExpression reduce(const std::vector<SymbolicExpression>& vec,
                          const std::function<SymbolicExpression(const SymbolicExpression&, const SymbolicExpression&)>& func) {
    if (vec.empty()) {
        return SymbolicExpression("0");
    }
    return std::accumulate(vec.begin() + 1, vec.end(), vec[0], func);
}


std::vector<std::string> recursive_split(const std::string& s, Indices& idx,
                                         std::unordered_map<std::string, std::vector<std::string>>& memo) {
    
    if (memo.find(s) != memo.end()) {
        return memo[s];
    }

    
    if (s.find('(') == std::string::npos) {
        
        int leaf_idx = idx.leaf_index++;
        Symbol tl("tl" + std::to_string(leaf_idx));
        Matrix current_matrix = createMatrixLeafGroup(tl);

        std::vector<std::string> result = {current_matrix.get(0, 0), current_matrix.get(1, 0),
                                           current_matrix.get(2, 0), current_matrix.get(3, 0)};
        memo[s] = result;
        return result;
    }

    
    auto parts = findsplit(s);
    std::vector<Matrix> matrices;

    for (const auto& part : parts) {
        Indices child_idx = idx;
        auto child_result = recursive_split(part[0], child_idx, memo);

        Matrix child_matrix(4, 1);
        for (int i = 0; i < 4; ++i) {
            child_matrix.set(i, 0, child_result[i]);
        }

        if (part[0].find('(') != std::string::npos) {
            
            int edge_num = idx.edge_num++;
            Symbol t("t" + std::to_string(edge_num));
            Symbol c("c" + std::to_string(edge_num));
            Matrix internal_matrix = createMatrixInternal(t, c);
            matrices.push_back(multiplyMatrices(internal_matrix, child_matrix));
        } else {
            matrices.push_back(child_matrix);
        }
    }

    Matrix combined_matrix = combine(matrices);

    std::vector<std::string> result = {combined_matrix.get(0, 0), combined_matrix.get(1, 0),
                                       combined_matrix.get(2, 0), combined_matrix.get(3, 0)};
    memo[s] = result;
    return result;
}


std::vector<std::vector<std::string>> findsplit(const std::string& s) {
    std::vector<std::vector<std::string>> result;
    std::stack<char> stack;
    std::string current_part;

    for (size_t i = 1; i < s.length() - 1; ++i) {
        char ch = s[i];
        if (ch == ',' && stack.empty()) {
            result.push_back({current_part});
            current_part.clear();
        } else {
            current_part += ch;
            if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                if (!stack.empty()) {
                    stack.pop();
                }
            }
        }
    }
    if (!current_part.empty()) {
        result.push_back({current_part});
    }

    return result;
}


Matrix combine(const std::vector<Matrix>& matrices) {
    std::vector<SymbolicExpression> v_not_invented, v_lost, v_fixed, v_polymorphic;
    for (const auto& mat : matrices) {
        v_not_invented.push_back(SymbolicExpression(mat.get(0, 0)));
        v_lost.push_back(SymbolicExpression(mat.get(1, 0)));
        v_fixed.push_back(SymbolicExpression(mat.get(2, 0)));
        v_polymorphic.push_back(SymbolicExpression(mat.get(3, 0)));
    }

    SymbolicExpression v_l = all(v_lost, "1") ? SymbolicExpression("1") : SymbolicExpression("0");
    SymbolicExpression v_f = all(v_fixed, "1") ? SymbolicExpression("1") : SymbolicExpression("0");
    SymbolicExpression v_p = reduce(v_polymorphic, [](const SymbolicExpression& a, const SymbolicExpression& b) { return a * b; });

    SymbolicExpression v_n("0");
    if (all(v_lost, "0")) {
        v_n = SymbolicExpression("0");
    } else if (all(v_lost, "1")) {
        v_n = reduce(v_not_invented, [](const SymbolicExpression& a, const SymbolicExpression& b) { return a + b; });
    } else {
        std::vector<SymbolicExpression> introduce_index;
        for (size_t i = 0; i < v_lost.size(); ++i) {
            if (v_lost[i].toString() == "0") {
                introduce_index.push_back(v_not_invented[i]);
            }
        }
        v_n = reduce(introduce_index, [](const SymbolicExpression& a, const SymbolicExpression& b) { return a + b; });
    }

    return Matrix({{v_n.toString()}, {v_l.toString()}, {v_f.toString()}, {v_p.toString()}});
}


Matrix multiplyMatrices(const Matrix& a, const Matrix& b) {
    Matrix result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            SymbolicExpression sum("0");
            for (int k = 0; k < a.getCols(); ++k) {
                sum = sum + SymbolicExpression(a.get(i, k)) * SymbolicExpression(b.get(k, j));
            }
            result.set(i, j, sum.toString());
        }
    }
    return result;
}
