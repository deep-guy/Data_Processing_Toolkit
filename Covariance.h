#ifndef COVARIANCE
#define COVARIANCE
#include "Matrix.h"
#include "useful.h"
#include "Square.h"

class Covariance: public Square
{
  private:
    Matrix orig;
    double getVariance(vector<double> &v);
    string filename;

  public:
    Covariance(string filename):Square(filename){};

    void compute();
};

#endif;