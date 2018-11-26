#include "Matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(int m, int n)
{
    _m = m;
    _n = n;
    // v.resize(_m);
    // for(int i=0;i<_m;i++) v[i].assign(_n,0);
}

Matrix::Matrix(string filename)
{
    ifstream in( filename );
    string line;
    int countline = 0;
    while ( getline( in, line ) )                   // read a whole line of the file
    {
        
        stringstream ss( line );                     // put it in a stringstream (internal stream)
        vector<double> row;
        string data;

        if(countline==0) // The first row is filled with names
        {
            countline = 1;
            while ( getline( ss, data, ',' ) )  
            {
                _names.push_back(data);           
            }
            continue;
        }

        while ( getline( ss, data, ',' ) )           // read (string) items up to a comma
        {
            row.push_back( stod( data ) );            // use stod() to convert to double; put in row vector
        }
        if ( row.size() > 0 ) _matrix.push_back( row );    // add non-empty rows to matrix
    }

    _m = _matrix.size();
    _n = _matrix[0].size();
}

void Matrix::output_to_csv(string filename)
{
    ofstream out;
    out.open(filename);

    for(int i=0;i<_permutation.size();i++) out<<_permutation[i]<<" ";cout<<endl;

    out<<_m<<" "<<_n<<endl;
    for(int i=0;i<_m;i++)
    {
        for(int j=0;j<_n-1;j++)
        {
            out<<_matrix[i][j]<<", ";
        }
        out<<_matrix[i][_n-1]<<endl;
    }
    out<<"eof"<<endl;
}

vector<double> Matrix::get_row(int i)
{
    return _matrix[i];
}

vector<double> Matrix::get_column(int k)
{
    vector<double> column;
    for(int i=0;i<_m;i++)
    {
        column.push_back(_matrix[i][k]);
    }
    return column;
}

void Matrix::setElement(int i,int j,double k)
{
    _matrix[i][j] = k;
}


int main()
{
    return 0;
}
