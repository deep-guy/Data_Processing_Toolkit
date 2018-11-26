#ifndef MATRIX_H_
#define MATRIX_H_

#include <bits/stdc++.h>
using namespace std;

// This is the base class that we will be using for the project;
// Add the individual methods as a part of your task into this class

class Matrix
{
    private:
        int _m, _n;
        // This is used because vector can return the size
        // We can directly get the dimensions of the grid without needing the user to input it
        // Note the type is a double because our calculations will be floating point based
        vector<vector<double> > _matrix; 
        vector<string> _names; // Stores the names in the frist row of the csv
    
    public:
        Matrix();
        Matrix(string filename);
        Matrix(int, int);
        // ~Matrix(); Vectors don't need explicit destructors

        
        //getters
        int get_rows() {return _m;}
        int get_columns() {return _n;}
        vector<double> get_row(int i);
        vector<double> get_column(int i);
        vector<vector<double> > get_matrix() {return _matrix;}
        vector<string> get_names() {return _names;}

        void output_to_csv(string filename); // Make sure the filename ends with a ".csv"
        void setElement(int i,int j,double k);
};

#endif