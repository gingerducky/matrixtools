#include <iostream>
#include <vector>
#include "matrixtools.hpp"

using namespace std;
using namespace matrixtools;

int main(void) {
    Matrix m(2, 2, 1.0), b(2, 2, 2.0), c, d;

    c = m + b;
    d = m * b;
    c.showMatrix();
    d.showMatrix();
    c *= 5;
    c.showMatrix();
    return 0;
}
