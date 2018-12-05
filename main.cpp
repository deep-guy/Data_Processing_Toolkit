#include<bits/stdc++.h>
#include "Covariance.h"
#include "Distance_Matrix.h"
#include "Dataset.h"
#include "ROBINSONIAN_REORDERING.h"
#include "useful.h"
#include "Task1.h"
#include "Basic_Min_Ordering.h" 
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

int main()
{
  string s = "Datasets/PRSA.csv";
  Dataset d(s);
  string k1 = "DistMat.csv";
  while(true)
  {
    cout<<"Select 1 for Covariance"<<endl<<"Select 2 for Distance"<<endl<<"Select 3 for Robinsonian Reordering"<<endl<<"Select 4 for k-Clustering"<<endl<<"Select 5 for Minimum Ordering"<<endl<<"Else press anything else to exit"<<endl;
    int n;
    sc(n);
    if(n==1)
    {
      Covariance cov(d);
      cov.compute();
    }
    else if(n==2)
    {
      DistanceMatrix d1(d);
      d1.compute();
    }
    else if(n==3)
    {
      Dataset d2(k1);
      Bipolarization b(d2);
      b.compute();
    }
    else if(n==4)
    {
      int k;
      cout<<"Input the number of clusters: ";
      sc(k);
      Task1 task(d);
      task.output1(k,d.getUserInput());
      task.output2(k,d.getUserInput());
    }
    else if(n==5)
    {
      Dataset d2(k1);
      Basic_min_ordering bss(d2);
      bss.compute();
    }
    else break;
  }
  // string s = "data.csv";
  
  return 0;
}
