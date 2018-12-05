#ifndef Basic_Min_ordering_h_
#define Basic_Min_ordering_h_
#include "Matrix.h"
#include "useful.h"
#include "Square.h"
#include "Dataset.h"

class Basic_min_ordering: public Square
{
  private:
    // Matrix _INPUT;
    vector< pair <int,int> > basic_min_ordering();
    void Result();

  public:
    Basic_min_ordering(Dataset &d): Square(d) {}
    void compute();
};

#endif
