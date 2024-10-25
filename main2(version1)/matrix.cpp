#include "matrix.h"
#include <stdexcept>

Matrix::Matrix(int rows, int cols) : data(rows, std::vector<std::string>(cols)) {}

Matrix::Matrix(const std::vector<std::vector<std::string>>& elements) : data(elements) {}

std::string Matrix::get(int row, int col) const {
    return data.at(row).at(col);
}

void Matrix::set(int row, int col, const std::string& value) {
    data.at(row).at(col) = value;
}

int Matrix::getRows() const {
    return data.size();
}

int Matrix::getCols() const {
    return data.empty() ? 0 : data[0].size();
}

Matrix createMatrixLeafGroup(const Symbol& tl) {
    return Matrix({
        {"0", "0", "0", "0"},
        {"0", "1", "0", "0"},
        {"0", "0", "1", "0"},
        {"0", "(1 - " + tl.getName() + ") / 2", "(1 - " + tl.getName() + ") / 2", tl.getName()}
    });
}

Matrix createMatrixInternal(const Symbol& t, const Symbol& c) {
    return Matrix({
        {"1", "(-log(" + t.getName() + ")-(1-" + t.getName() + "))*exp(" + c.getName() + ")/2", "(-log(" + t.getName() + ")-(1-" + t.getName() + "))*exp(" + c.getName() + ")/2", "exp(" + c.getName() + ")*(1-" + t.getName() + ")"},
        {"0", "1", "0", "0"},
        {"0", "0", "1", "0"},
        {"0", "(1-" + t.getName() + ")/2", "(1-" + t.getName() + ")/2", t.getName()}
    });
}

Matrix createMatrixLeaf() {
    return Matrix({
        {"0", "0", "0", "0"},
        {"0", "1", "0", "0"},
        {"0", "0", "1", "0"},
        {"0", "1/2", "1/2", "1"}
    });
}
