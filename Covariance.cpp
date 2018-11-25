#include<bits/stdc++.h>
#include "Covariance.h"
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

Covariance::Covariance(Matrix &orig)
{
  this->orig = orig;
}

double Covariance::getAvg(vector<double> &v)
{
  double avg = 0;
  for(int i=0;i<v.size();i++) avg+=v[i];
  avg/=v.size();
  return avg;
}

double Covariance::getVariance(vector<double> &v)
{
  double avg = 0,variance = 0;
  avg = getAvg(v);

  for(int i=0;i<v.size();i++)
  {
    variance+=pow((abs(v[i]-avg)),2);
  }
  variance/=v.size();
  return variance;
}


double Covariance::dot(vector<double> &v, vector<double> &w)
{
  double ans = 0;
  for(int i=0;i<v.size();i++)
  {
    ans+=v[i]*w[i];
  }
  return ans;
}

void Covariance::sub(vector<double> &v,int k)
{
  for(int i=0;i<v.size();i++) v[i]-=k;
}

void Covariance::compute()
{
  vector<double> variances;
  for(int i=0;i<orig.get_columns();i++)
  {
    vector<double> temp;
    for(int j=0;j<orig.get_rows();j++)
    {
      temp.pu(orig.get_matrix()[j][i]);
    }
    variances.pu(getVariance(temp));
  }

  Matrix ans(orig.get_columns(),orig.get_columns());

  for(int i=0;i<variances.size();i++)
  {
    for(int j=0;j<variances.size();j++)
    {
      vector<double> v = orig.get_column(i);
      vector<double> w = orig.get_column(j);
      sub(v,getAvg(v));
      sub(w,getAvg(w));
      double a = dot(v,w);
      a/=v.size();
      ans.setElement(i,j,a);
    }
  }
}



