#ifndef ROBINSONIAN_REORDERING_h
#define ROBINSONIAN_REORDERING_h
#include<bits/stdc++.h>
using namespace std;
#include "Square.h"
class Bipolarization : public Square
{
private:
  Matrix _output;
  void swap_row(vector<vector<double>> &arr,int x,int y,int z);
  void swap_col(vector<vector<double>> &arr,int x,int y,int z);
  void swap(vector<vector<double>> &arr,int row_s,int col_s,int row_e,int col_e,int size);
  void find_max(vector<vector<double>> &arr,int size,double* res);
  void search(double* res,bool direction,int x,int y,vector<vector<double>> &arr);
  void solve(vector<vector<double>> &arr,int size);
  void call_solve();
public:
  Bipolarization(Dataset &d) : Square(d)
  {
    /*ifstream in( filename );
    string line;
    int countline = 0;
    vector<vector<double> > matrix;
      //_output = Matrix(get_rows(), get_rows());
    while (getline( in, line ) )                   // read a whole line of the file
    {
        stringstream ss( line );                     // put it in a stringstream (internal stream)
        vector<double> row;
        string data;
        if(countline==0) // The first row is filled with names
        {
            countline = 1;
            while ( getline( ss, data, ',' ) )
            {
              //  _names.push_back(data);
            }
            continue;
        }
        if(countline==1)
        {
          countline=2;
          while ( getline( ss, data, ',' ) )
          {
              //row.push_back(stod(data));
          }
          row.clear();
        }
        while ( getline( ss, data, ',' ) )           // read (string) items up to a comma
        {
            //cout<<data<<endl;
            if(data=="eof") goto jump;
            row.push_back(stod(data));            // use stod() to convert to double; put in row vector
        }
        if ( row.size() > 0 )  matrix.push_back( row );    // add non-empty rows to matrix
    }
    jump:
    setMatrix(matrix);
    set_rows(matrix.size());
    set_columns( matrix[0].size());
    //for(int i=0;i<_n;i++) _permutation.push_back(i);*/
    }
  void compute();
};
#endif
