#include "Distance_Matrix.h"
using namespace std;

// DistanceMatrix::DistanceMatrix(Matrix &input)
// {
//     this->= input;
//     _output = Matrix(get_rows(), get_rows());
//     vector<vector<double> > v = _output.get_matrix();
//     v.resize(get_rows());
//     for(int i = 0; i < get_rows(); i++) 
//         v[i].assign(get_rows(),0);
//     _output.setMatrix(v);
// }

void DistanceMatrix::computeAverage()
{
    double average = 0;
    for (int i = 0; i < get_columns(); i++)
    {
        vector<double> column = get_column(i);
        for (int j = 0; j < get_rows(); j++)
        {
            average += column[j];
        }
        _avg_array.push_back(average);
        average = 0;
    }
}

void DistanceMatrix::computeDistance()
{
    double distance;
    _max_vector = 0;
    _min_vector = 100000000000;
    for (int i = 0; i < get_rows(); i++)
    {
        vector<double> row = get_row(i);
        for (int j = 0; j < get_columns(); j++)
        {
            double diff = row[j] - _avg_array[j];
            distance += diff * diff;
        }
        distance = sqrt(distance);
        _dist_array.push_back(distance);
        if (distance > _max_vector)
            _max_vector = distance;
        if (distance < _min_vector)
            _min_vector = distance;
        distance = 0;
    }
}

void DistanceMatrix::normaliseDistance()
{
    double divisor = _max_vector - _min_vector;
    for (int i = 0; i < get_rows(); i++)
    {
        _dist_array[i] = (_dist_array[i] - _min_vector)/ divisor;
    }
}

void DistanceMatrix::createDistanceMatrix()
{
    _output = Matrix(get_rows(), get_rows());
    vector<vector<double> > v = _output.get_matrix();
    v.resize(get_rows());
    for(int i = 0; i < get_rows(); i++) 
        v[i].assign(get_rows(),0);
    _output.setMatrix(v);

    vector<pair<double, int> > temp_distance;   
    for (int i = 0; i < _dist_array.size(); i++)
    {
        temp_distance.push_back(make_pair(_dist_array[i], i));
    }

    sort(temp_distance.begin(), temp_distance.end());

    for (int i = 0; i < temp_distance.size(); i++)
    {
        _dist_array[i] = temp_distance[i].first;
        _sort_map[i] = temp_distance[i].second;
    }

    for (int i = 0; i < _dist_array.size(); i++)
    {
        for (int j = 0; j < _dist_array.size(); j++)
        {
            double distance = 0;
            for (int k = 0; k < get_row(_sort_map[i]).size(); k++)
            {
                double diff = get_row(_sort_map[i])[k] - get_row(_sort_map[j])[k];
                distance += diff*diff;
            }
            distance = sqrt(distance);
            _output.setElement(i, j, distance);
        }
    }

    _output.output_to_csv("DistMat.csv");
}

void DistanceMatrix::compute()
{
    computeAverage();
    computeDistance();
    normaliseDistance();
    createDistanceMatrix();
}