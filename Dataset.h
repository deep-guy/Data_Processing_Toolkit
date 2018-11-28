#ifndef Dataset_H_
#define Dataset_H_

#include <iostream>
#include "Record.h"
#include <vector>
using namespace std;
class Dataset
{
    private:
        vector<vector<string>> dataset_ar;
    public:
        Dataset();
        Dataset(vector<vector<string>> dataset_ar1);
        ~Dataset();
        Dataset(const Dataset&);

        //getters
        vector<vector<string>> get_dataset_ar()
        {
            return dataset_ar;
        }
        vector<Record> get_vector_record()
        {
            vector<Record> record_Ar;
            for (int i = 0; i < dataset_ar.size(); i ++)
            {
                Record temp_record(dataset_ar[i]);
                record_Ar.push_back(temp_record);
            }
            return record_Ar;
        }
};

#endif
