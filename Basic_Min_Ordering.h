#ifndef Basic_Min_order
#define Basic_Min_order
#include "Matrix.h"
#include "useful.h"
#include "Square.h"
#include "Dataset.h"

class Basic_min_ordering: public Square
{
  private:
    Matrix _INPUT;
    vector< pair <int,int> > basic_min_ordering(vector<vector<double>> v,int p);
    void Result();
  public:
    void compute();
    Basic_min_ordering(Dataset &d): Square(d) {};
};

#endif
