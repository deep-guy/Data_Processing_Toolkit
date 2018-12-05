#include<iostream>
#include "Matrix.h"
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define fi first
#define se second
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;

Matrix::Matrix()
{

}

Matrix::Matrix(int m, int n)
{
    _m = m;
    _n = n;
    _matrix.resize(_m);
    for(int i=0;i<_m;i++) _matrix[i].assign(_n,0);
}

Matrix::Matrix(Dataset &d)
{
    _matrix = d.getMatrix();
    _m = _matrix.size();
    _n = _matrix[0].size();
    for(int i=0;i<_n;i++) _permutation.push_back(i);
}

void Matrix::output_to_csv(string filename)
{
    ofstream out;
    out.open(filename);

    // for(int i=0;i<_permutation.size();i++) out<<_permutation[i]<<" ";out<<endl;

    out<<_m<<" "<<_n<<endl;
    for(int i=0;i<_m;i++)
    {
        for(int j=0;j<_n-1;j++)
        {
            out<<_matrix[i][j]<<", ";
        }
        out<<_matrix[i][_n-1]<<endl;
    }
    out<<"eof"<<endl;
}

vector<double> Matrix::get_row(int i)
{
    return _matrix[i];
}

vector<double> Matrix::get_column(int k)
{
    vector<double> column;
    for(int i=0;i<_m;i++)
    {
        column.push_back(_matrix[i][k]);
    }
    return column;
}

void Matrix::setElement(int i,int j,double k)
{
    _matrix[i][j] = k;
}
