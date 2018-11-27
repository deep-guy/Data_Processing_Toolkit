#ifndef SQUARE
#define SQUARE

#include "Matrix.h"
#include <bits/stdc++.h>
using namespace std;


class Square : public Matrix
{

  public: 
    Square(string filename): Matrix(filename){};
    Square(int m): Matrix(m, m){};  
  protected:
    // The real computation for your algorithm
    // This should be the only public function in any inherited class
    // The rest are all private, visible to the inherited class only
    // Or you can add them to useful.cpp if they are generic
    virtual void compute() = 0; 
};

#endif
