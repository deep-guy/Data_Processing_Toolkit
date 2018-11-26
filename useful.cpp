#include<bits/stdc++.h>
#include "useful.h"
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define fi first
#define se second
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

double getAvg(vector<double> &v)
{
  double avg = 0;
  for(int i=0;i<v.size();i++) avg+=v[i];
  avg/=v.size();
  return avg;
}

double dot(vector<double> &v, vector<double> &w)
{
  double ans = 0;
  for(int i=0;i<v.size();i++)
  {
    ans+=v[i]*w[i];
  }
  return ans;
}

void sub(vector<double> &v,int k)
{
  for(int i=0;i<v.size();i++) v[i]-=k;
}

double min(double x,double y)
{
  if(x<y) return x;
  return y;
}

double max(double x,double y)
{
  if(x>y) return x;
  return y;
}

void normalize(vector<double> &v)
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

void normalize(vector<vector<double> > &v)
{
  double max1 = -1, min1 = INF;
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      max1 = max(max1,v[i][j]);
      min1 = min(min1,v[i][j]);
    }
  }

  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      if(max1!=min1) v[i][j] = (v[i][j]-min1)/(max1-min1);
      else v[i][j] = 1;
    }
  }

}

void sorted_normalized(vector<double> &v,map<int,int> &d)
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

void p(vector<double>&v)
{
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
}


