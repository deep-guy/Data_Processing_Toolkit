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

double Covariance::min(double x,double y)
{
  if(x<y) return x;
  return y;
}

double Covariance::max(double x,double y)
{
  if(x>y) return x;
  return y;
}

void Covariance::normalize(vector<double> &v)
{
  double max1 = -1, min1 = INF;
  for(int i=0;i<v.size();i++)
  {
    min1 = min(min1,v[i]);
    max1 = max(max1,v[i]);
  }

  if(max1==min1)
  {
    for(int i=0;i<v.size();i++) v[i] = 1;
  }
  else
  {
    for(int i=0;i<v.size();i++)
    {
      v[i] = (v[i]-min1)/(max1-min1);
    }
  }
}

void Covariance::sorted_normalized(vector<double> &v,map<int,int> &d)
{
  vector<pair<double,int> > temp_variance;
  normalize(v);

  for(int i=0;i<v.size();i++) 
  {
    temp_variance.pu(mp(v[i],i));
  }

  sort(temp_variance.begin(),temp_variance.end());

  for(int i=0;i<temp_variance.size();i++) 
  {
    v[i] = temp_variance[i].fi;
    d[i] = temp_variance[i].se;
  }

}

void Covariance::compute()
{
  // vector<pair<double,string> > variances;
  vector<double> variance;
  map<int,int> getOrigPos;
  for(int i=0;i<orig.get_columns();i++)
  {
    vector<double> temp;
    for(int j=0;j<orig.get_rows();j++)
    {
      temp.pu(orig.get_matrix()[j][i]);
    }
    variance.pu(getVariance(temp));
  }

  sorted_normalized(variance,getOrigPos);
  
  Matrix ans(orig.get_columns(),orig.get_columns());

  for(int i=0;i<variance.size();i++)
  {
    for(int j=0;j<variance.size();j++)
    {
      vector<double> v = orig.get_column(getOrigPos[i]);
      vector<double> w = orig.get_column(getOrigPos[j]);
      sub(v,getAvg(v));
      sub(w,getAvg(w));
      double a = dot(v,w);
      a/=v.size();
      ans.setElement(i,j,a);
    }
  }

  ans.output_to_csv("Covariance Matrix.csv");

}



