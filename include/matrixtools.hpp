#pragma once
#include <vector>

namespace matrixtools {
    
    using ld = long double;

    class Matrix {
    public:
        int rows;
        int columns;
        std::vector<std::vector<ld>> data;

        Matrix(int trows = 0, int tcolumns = 0, ld initialValAll = 0.0);

        bool isSameSize(const Matrix& other) const;
        bool areColumnsEqualToRows(const Matrix& other) const;
        
        void showMatrix() const;
        
        //add determinant, use loops because recursive version will probably cause an overflow on larger matrices
        //add foundational row operations

        Matrix& operator*= (ld scalar);

        Matrix& operator+= (const Matrix& other);
    };

    Matrix operator* (Matrix m, ld scalar);
    Matrix operator* (ld scalar, Matrix m);
    
    Matrix operator* (const Matrix& m, const Matrix& other);
    
    Matrix operator+ (Matrix m, const Matrix& other);
}
