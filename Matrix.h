#ifndef MATRIX_H_
#define MATRIX_H_

#include <string>
using namespace std;

// This is the base class that we will be using for the project;
// Add the individual methods as a part of your task into this class

class Matrix
{
    private:
        int _m, _n;
        int** _matrix;
    
    public:
        Matrix(string filename);
        Matrix(int, int);
        ~Matrix();
        
        //getters
        void output_to_csv();
        int get_rows() {return _m;}
        int get_columns() {return _n;}
        int** get_matrix() {return _matrix;}
};

#endif