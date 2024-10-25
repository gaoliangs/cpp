#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "symbol.h"

class Matrix {
public:
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<std::string>>& elements);
    std::string get(int row, int col) const;
    void set(int row, int col, const std::string& value);
    int getRows() const;
    int getCols() const;

private:
    std::vector<std::vector<std::string>> data;
};

Matrix createMatrixLeafGroup(const Symbol& tl);
Matrix createMatrixInternal(const Symbol& t, const Symbol& c);
Matrix createMatrixLeaf();

#endif
