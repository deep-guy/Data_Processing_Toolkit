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
  Bipolarization(string filename) : Square(filename) {}
  void compute();
};
#endif
