#include "ROBINSONIAN_REORDERING.h"
#include<bits/stdc++.h>
using namespace std;
#define i first
#define j second
void Bipolarization::swap_row(vector<vector<double>> &arr,int x,int y,int z)
{
  vector<double> temp;
  for(int i=0;i<z;i++) temp.push_back(arr[x][i]);
  for(int i=0;i<z;i++) arr[x][i]=arr[y][i];
  for(int i=0;i<z;i++) arr[y][i]=temp[i];
}
void Bipolarization::swap_col(vector<vector<double>> &arr,int x,int y,int z)
{
  vector<double> temp;
  for(int i=0;i<z;i++) temp.push_back(arr[i][x]);
  for(int i=0;i<z;i++) arr[i][x]=arr[i][y];
  for(int i=0;i<z;i++) arr[i][y]=temp[i];
}
void Bipolarization::swap(vector<vector<double>> &arr,int row_s,int col_s,int row_e,int col_e,int size)
{
  int swap_size=abs(row_s-row_e);
  int j,k,mov;
  if(row_s<row_e) mov=1;
  else mov=-1;
  j=row_s;
  k=j+mov;
  for(int i=0;i<swap_size;i++)
  {
    swap_row(arr,j,k,size);
    swap_col(arr,j,k,size);
    j=j+mov;
    k=k+mov;
  }
  swap_size=abs(col_s-col_e);
  if(col_s<col_e) mov=1;
  else mov=-1;
  j=col_s;
  k=j+mov;
  for(int i=0;i<swap_size;i++)
  {
    swap_col(arr,j,k,size);
    swap_row(arr,j,k,size);
    j=j+mov;
    k=k+mov;
  }
}
void Bipolarization::find_max(vector<vector<double>> &arr,int size,double* res)
{
  res[0]=arr[0][0];
  res[1]=res[2]=0;
  int temp;
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
    {
      if(res[0]<arr[i][j]) {res[0]=arr[i][j],res[1]=i,res[2]=j;}
    }
  }
  if(res[1]<res[2])
  {
    temp=res[1];
    res[1]=res[2];
    res[2]=temp;
  }
}
void Bipolarization::search(double* res,bool direction,int x,int y,vector<vector<double>> &arr)
{
  res[0]=arr[x][y];
  res[1]=x;
  res[2]=y;
  if(direction)
  {
    res[1]=x;
    for(int k=y;k!=x;k++)
    {
      if(res[0]<arr[x][k]) {res[0]=arr[x][k],res[2]=k;}
    }
  }
  else
  {
    res[2]=y;
    for(int k=x;k!=y;k--)
    {
      if(res[0]<arr[k][y]) {res[0]=arr[k][y],res[1]=k;}
    }
  }
}
void Bipolarization::solve(vector<vector<double>> &arr,int size)
{
  double *res1,*res2;
  res1=new double[3];
  res2=new double[3];
  find_max(arr,size,res1);
  swap(arr,res1[1],res1[2],size-1,0,size);
  pair<int,int> P1,P2,P3;
  P1.i=size-1;
  P1.j=0;
  P2.i=P1.i;
  P2.j=P1.j+1;
  P3.i=P1.i-1;
  P3.j=P1.j;
  int temp;
  bool row_direction;
  while(P1.i!=P1.j)
  {
    while(P2.i!=P2.j)
    {
      search(res1,true,P2.i,P2.j,arr);
      search(res2,false,P3.i,P3.j,arr);
      if(res1[0]>res2[0]) row_direction=true;
      else row_direction=false;
      for(int cnt=0;cnt<2;cnt++)
      {
        if(row_direction)
        {
          swap(arr,res1[1],res1[2],P2.i,P2.j,size);
          P2.j++;
          search(res2,false,P3.i,P3.j,arr);
        }
        else
        {
          swap(arr,res2[1],res2[2],P3.i,P3.j,size);
          P3.i--;
          search(res1,true,P2.i,P2.j,arr);
        }
        row_direction=!row_direction;
      }
    }
    P1.i--;
    P1.j++;
    P2.i=P1.i;
    P2.j=P1.j+1;
    P3.i=P1.i-1;
    P3.j=P1.j;
  }
}
void Bipolarization::call_solve()
{
  vector<vector<double>> v;
  v.resize(get_rows());
  for(int i = 0; i < get_rows(); i++)
      v[i].assign(get_rows(),0);
  v=get_matrix();
  solve(v,get_rows());
  _output = Matrix(get_rows(), get_rows());
  _output.setMatrix(v);
  _output.output_to_csv("Robinsonian.txt");
}
void Bipolarization::compute()
{
  call_solve();
}
