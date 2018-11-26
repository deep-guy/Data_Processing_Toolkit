#include<bits/stdc++.h>
#include "Covariance.h"
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


using namespace std;

// Covariance::Covariance(Matrix &orig)
// {
//   this->orig = orig;
// }


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


void Covariance::compute()
{
  // vector<pair<double,string> > variances;
  vector<double> variance;
  map<int,int> getOrigPos;
  for(int i=0;i<get_columns();i++)
  {
    vector<double> temp;
    for(int j=0;j<get_rows();j++)
    {
      temp.pu(get_matrix()[j][i]);
    }
    variance.pu(getVariance(temp));
  }

  // for(int i=0;i<variance.size();i++) cout<<variance[i]<<" ";cout<<endl;
  sorted_normalized(variance,getOrigPos);
  
  // Setting the permutatiom
  for(int i=0;i<_permutation.size();i++) _permutation[i] = getOrigPos[_permutation[i]];

  Matrix ans(get_columns(),get_columns());

  for(int i=0;i<variance.size();i++)
  {
    for(int j=0;j<variance.size();j++)
    {
      // vector<double> v = get_column(getOrigPos[i]);
      // vector<double> w = get_column(getOrigPos[j]);
      vector<double> v = get_column(i);
      vector<double> w = get_column(j);
      sub(v,getAvg(v));
      sub(w,getAvg(w));
      double a = dot(v,w);
      a/=v.size();
      ans.setElement(i,j,a);
    }
  }

  ans.setPermutation(_permutation);
  normalize(ans.get_matrix());
  ans.output_to_csv("Covariance Matrix.csv");

}



