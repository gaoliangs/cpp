#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include "symbol.h"
#include "symbolic.h"

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<std::string>> data;

public:
    Matrix(int r, int c);
    Matrix(const std::vector<std::vector<std::string>>& d);
    int getRows() const;
    int getCols() const;
    std::string get(int r, int c) const;
    void set(int r, int c, const std::string& value);
};

// 在这里声明函数
Matrix createMatrixInternal(const Symbol& t, const Symbol& c);
Matrix createMatrixLeafGroup(const Symbol& tl);
Matrix createMatrixLeaf();

#endif // MATRIX_H
