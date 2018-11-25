#ifndef COVARIANCE
#define COVARIANCE
#include "Matrix.h"

class Covariance
{
  private:
    Matrix orig;

  public:
    Covariance(Matrix &orig);

    void compute();
    double getVariance(vector<double> &v);
    double getAvg(vector<double> &v);
    double dot(vector<double> &v, vector<double> &w);
    void sub(vector<double>&v,int k);
};

#endif;