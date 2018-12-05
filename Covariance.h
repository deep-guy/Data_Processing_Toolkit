#ifndef COVARIANCE
#define COVARIANCE
#include "Matrix.h"
#include "useful.h"
#include "Square.h"

class Covariance: public Square
{
  private:
    double getVariance(vector<double> &v);

  public:
    Covariance(Dataset &d):Square(d){};

    void compute();
};

#endif