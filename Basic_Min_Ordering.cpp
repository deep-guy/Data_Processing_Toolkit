#include <bits/stdc++.h>
#include "Basic_Min_order.h"
#include <iosteam>
#include <fstream>
using namespace std;

vector < pair < int,int> > basic_min_ordering()
{
  int p = get_rows();
  vector<vector<double>> sqr_mat = get_matrix();  
  vector< pair <int,int> > vect;
  vector<double> degree;
  for(int i=0;i<p;i++)
  {
    double sum = 0;
    for(int j=0;j<p;j++)
    {
      if(i != j)
        sum = sum + sqr_mat[i][j];
    }
    degree.push_back(sum);
  }
  for(int i=0;i<p;i++){
    int index = 0;
    double min = INT_MAX;
    for(int i=0;i<p;i++)
    {
      if(min>degree[i])
      {
        min = degree[i];
        index = i;
      }
    }
    vect.push_back(make_pair(index,index));
    for(int i=0;i<p;i++)
    {
      if(i != index)
        degree[i] = degree[i] - sqr_mat[index][i];
      else
        degree[i] = INT_MAX;
    }
  }
  return vect;
}

void Result(){
    ofstream _result;
    std::vector<pair<int>> v;
    vector<vector<double>> sqr_mat;
    sqr_mat.resize(get_rows());
    for(int i=0;i<get_rows();i++)
      sqr_mat[i].assign(get_rows(),0);
    sqr_mat = get_matrix();
    v = basic_min_ordering(sqr_mat,get_rows());
    _result.open("output.txt");
    for(int i=0;i<get_rows;i++)
    {
      _result<<v[i].first<<","<<v[i].second<<endl;
    }
    _result<<"eof"<<endl;;
    _result.close();
}


void compute()
{
  Result();
}
