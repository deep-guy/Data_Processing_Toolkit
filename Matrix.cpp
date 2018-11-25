#include "Matrix.h"

Matrix::Matrix(int m, int n)
{
    _m = m;
    _n = n;
    _matrix = new int*[_m];
    for (int i = 0; i < _m; i++)
    {
        _matrix[i] = new int[_n];
    }
}