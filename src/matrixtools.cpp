#include "matrixtools.hpp"
#include <vector>
#include <iostream>

using namespace std;

namespace matrixtools {
    
    Matrix::Matrix(int trows, int tcolumns, ld initialValAll) : rows(trows), columns(tcolumns),
        data(trows, vector<ld>(tcolumns, initialValAll)) {}
    
    bool Matrix::isSameSize(const Matrix& other) const {
        if (rows == other.rows && columns == other.columns) return true;
        return false;
    }

    bool Matrix::areColumnsEqualToRows(const Matrix& other) const {
        if (columns == other.rows) return true;
        return false;
    }

    void Matrix::showMatrix() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << val << ' ';
            cout << endl;
        }
    }

    Matrix& Matrix::operator*= (ld scalar) {
        for (auto& row: data)
            for (auto& val : row)
                val *= scalar;

        return *this;
    }


    Matrix& Matrix::operator+= (const Matrix& other) {
        if (!isSameSize(other)) {
            cerr << "Matrix addition requires that the Matrices are of the same size" << endl;
            exit(1);
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                data[i][j] += other.data[i][j];

        return *this;
    }

    Matrix operator* (Matrix m, ld scalar) {
        m *= scalar;
        return m;
    }

    Matrix operator* (ld scalar, Matrix m) {
        m *= scalar;
        return m;
    }

    Matrix operator* (const Matrix& m, const Matrix& other) {
        if (!m.areColumnsEqualToRows(other)) {
            cerr << "Matrix multiplication requires that the first matrix has the same amount of columns as the amount of rows in the second matrix!" << endl;
            exit(1);
        }

        Matrix result(m.rows, other.columns, 0.0);

        for (int i = 0; i < m.rows; ++i)
            for (int k = 0; k < m.columns; ++k)
                for (int j = 0; j < other.columns; ++j)
                    result.data[i][j] += m.data[i][k] * other.data[k][j];

        return result;
    }

    Matrix operator+ (Matrix m, const Matrix& other) {
        m += other;
        return m;
    }
}
