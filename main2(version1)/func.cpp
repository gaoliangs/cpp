#include "func.h"
#include <stack>
#include <numeric>
#include <algorithm>
#include <functional>
#include "symbolic.h"


bool all(const std::vector<SymbolicExpression>& vec, const std::string& value);
SymbolicExpression reduce(const std::vector<SymbolicExpression>& vec, 
                          const std::function<SymbolicExpression(const SymbolicExpression&, const SymbolicExpression&)>& func);

std::vector<std::vector<std::string>> findsplit(const std::string& s, std::vector<int>& edge_index, std::vector<int>& taxa_index) {
    std::vector<std::vector<std::string>> result;
    std::stack<char> stack;
    int edge_idx = edge_index[0];
    int taxa_idx = taxa_index[0];
    std::string current_part;

    for (size_t i = 1; i < s.length() - 1; ++i) {
        char ch = s[i];
        if (ch == ',' && stack.empty()) {
            std::string string = current_part;
            int taxanum = std::count(string.begin(), string.end(), ',') + 1;
            int edgenum = std::count(string.begin(), string.end(), '(');
            result.push_back({string, 
                              std::to_string(edge_idx + 1) + "," + std::to_string(edge_idx + edgenum),
                              std::to_string(taxa_idx) + "," + std::to_string(taxa_idx + taxanum - 1)});
            edge_idx += edgenum;
            taxa_idx += taxanum;
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

    std::string string = current_part;
    int taxanum = std::count(string.begin(), string.end(), ',') + 1;
    int edgenum = std::count(string.begin(), string.end(), '(');
    result.push_back({string, 
                      std::to_string(edge_idx + 1) + "," + std::to_string(edge_idx + edgenum),
                      std::to_string(taxa_idx) + "," + std::to_string(taxa_idx + taxanum - 1)});

    return result;
}

Matrix combine(const std::vector<Matrix>& vector) {
    std::vector<SymbolicExpression> v_not_invented, v_lost, v_fixed, v_polymorphic;
    for (const auto& mat : vector) {
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

Matrix recursive_split(const std::string& s, std::vector<int>& edge_num, std::vector<int>& leaf_index, 
                       const std::vector<int>& smloc, const std::vector<Symbol>& t, const std::vector<Symbol>& c, 
                       const std::vector<Symbol>& tl) {
    if (s.find('(') != std::string::npos) {
        auto parts = findsplit(s, edge_num, leaf_index);
        std::vector<Matrix> result;
        for (const auto& part : parts) {
            if (part[0].find('(') == std::string::npos) {
                std::vector<int> part_edge_num = {std::stoi(part[1].substr(0, part[1].find(',')))};
                std::vector<int> part_leaf_index = {std::stoi(part[2].substr(0, part[2].find(',')))};
                result.push_back(recursive_split(part[0], part_edge_num, part_leaf_index, smloc, t, c, tl));
            } else {
                std::vector<int> part_edge_num = {std::stoi(part[1].substr(0, part[1].find(',')))};
                std::vector<int> part_leaf_index = {std::stoi(part[2].substr(0, part[2].find(',')))};
                auto v = recursive_split(part[0], part_edge_num, part_leaf_index, smloc, t, c, tl);
                int e = part_edge_num[0];
                Matrix current_matrix = createMatrixInternal(t[e], c[e]);
                result.push_back(multiplyMatrices(current_matrix, v));
            }
        }
        return combine(result);
    } else {
        Matrix current_matrix(4, 1);
        if (std::find(smloc.begin(), smloc.end(), leaf_index[0]) != smloc.end()) {
            current_matrix = createMatrixLeaf();
        } else {
            current_matrix = createMatrixLeafGroup(tl[leaf_index[0]]);
        }
        if (s == "0") {
            return multiplyMatrices(current_matrix, Matrix({{"1"}, {"1"}, {"0"}, {"0"}}));
        }
        if (s == "1") {
            return multiplyMatrices(current_matrix, Matrix({{"0"}, {"0"}, {"1"}, {"0"}}));
        }
        if (s == "01") {
            return multiplyMatrices(current_matrix, Matrix({{"0"}, {"0"}, {"0"}, {"1"}}));
        }
        if (s == "?") {
            return Matrix({{"1"}, {"1"}, {"1"}, {"1"}});
        }
        return current_matrix;
    }
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

// 辅助函数
bool all(const std::vector<SymbolicExpression>& vec, const std::string& value) {
    return std::all_of(vec.begin(), vec.end(), [&value](const SymbolicExpression& expr) { return expr.toString() == value; });
}

SymbolicExpression reduce(const std::vector<SymbolicExpression>& vec, 
                          const std::function<SymbolicExpression(const SymbolicExpression&, const SymbolicExpression&)>& func) {
    return std::accumulate(vec.begin() + 1, vec.end(), vec[0], func);
}
