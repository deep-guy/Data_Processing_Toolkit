#ifndef DISTANCE_MATRIX_H_
#define DISTANCE_MATRIX_H_
#include "Matrix.h"
#include "Square.h"
using namespace std;

class DistanceMatrix : public Square
{
    private:
        // Matrix _input;
        Matrix _output;
        double _min_vector;
        double _max_vector;
        vector<double> _avg_array;
        vector<double> _dist_array;
        map<int, int> _sort_map;

        //Private methods
        void computeAverage();
        void computeDistance();
        void normaliseDistance();
        void createDistanceMatrix();

    public:
        DistanceMatrix(string filename) : Square(filename) {}
        void compute();
};

#endif