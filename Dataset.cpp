#include<bits/stdc++.h>
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

#include "Dataset.h"

using namespace std;

Dataset::Dataset(){}
// Dataset::Dataset(vector<vector<string>> dataset_ar1)
// {
//     dataset_ar = dataset_ar1;
// }
Dataset::~Dataset()
{
    for (int i = 0; i < dataset_ar.size(); i ++)
    {
        dataset_ar[i].clear();
    }
    dataset_ar.clear();
}
Dataset::Dataset(const Dataset& dataset1)
{
    dataset_ar = dataset1.dataset_ar;
}

Dataset::Dataset(string filename,int data)
{
    ifstream in( filename );
    string line;
    int countline = 0;
    while (getline( in, line ) )                   // read a whole line of the file
    {
        stringstream ss( line );                     // put it in a stringstream (internal stream)
        vector<string> row;
        string data;
        
        if(countline==0) // The first row is filled with names
        {
            countline = 1;
            // while ( getline( ss, data, ',' ) )  
            // {
            //     _names.push_back(data);           
            // }
            continue;
        }

        while ( getline( ss, data, ',' ) )           // read (string) items up to a comma
        {
            row.push_back( data);            // use stod() to convert to double; put in row vector
        }
        if(row.size()==1 && row[row.size()-1]=="eof") continue;
        if ( row.size() > 0 ) dataset_ar.push_back( row );    // add non-empty rows to matrix
    }

    _m = dataset_ar.size();
    _n = dataset_ar[0].size();

    // If data is 1, then it's a csv of records and not a matrix. In that case, the user needs to input the number of non-numeric data members
    if(data==1) 
    {
        cout<<"Enter the number of non-numeric variables in the file "<<filename<<": ";
        int n;
        sc(n);
        convert(n);
    }
    else
    {
        for(int i=0;i<dataset_ar.size();i++)
        {
            for(int j=0;j<dataset_ar[i].size();j++) cout<<dataset_ar[i][j]<<" ";cout<<endl;
        }
    }
    // for(int i=0;i<_n;i++) _permutation.push_back(i);
}

void Dataset::convert(int n)
{
    for(int i=0;i<dataset_ar.size();i++)
    {
        vector<double> v;
        for(int j=n;j<dataset_ar[i].size();j++)
        {
            v.pu(stod(dataset_ar[i][j]));
        }
        convertToMatrix.pu(v);

    }
}
