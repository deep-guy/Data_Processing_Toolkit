#ifndef Record_H_
#define Record_H_

#include <iostream>
#include <vector>
using namespace std;
class Record
{
    private:
        vector<string> record_ar;
    public:
        Record();
        Record(vector<string> record_ar1);
        ~Record();
        Record(const Record&);

        //getters
        vector<string> get_record_ar()
        {
            return record_ar;
        }
};

#endif
