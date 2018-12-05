#ifndef USEFUL
#define USEFUL
#include<bits/stdc++.h>
#include "Record.h"

using namespace std;

double getAvg(vector<double> &v);
double dot(vector<double> &v, vector<double> &w);
void sub(vector<double>&v,int k);
void normalize(vector<double> &v);
void normalize(vector<vector<double> > &v);
void sorted_normalized(vector<double> &v,map<int,int> &d);
double min(double x,double y);
double max(double x,double y);
void p(vector<double> &v);
void output_record_to_csv(vector<Record> v, string filename);
#endif
