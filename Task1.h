#ifndef Task1_H_
#define Task1_H_

#include <bits/stdc++.h>
#include "Record.h"
#include "Dataset.h"
#include "Matrix.h"
#include "useful.h"
using namespace std;
class Task1
{
    private:
        vector<Record> records_ar;
        Dataset data;
    public:
        Task1();
        Task1(Dataset &d);
        // ~Task1();
        Task1(const Task1&);
        vector<vector<double>> delete_n(int n)
        {
            vector<Record> temp = records_ar;
            vector<vector<double>> double_ar;
            double_ar = data.getMatrix();
            return double_ar;
        }
        
        double compute_similarity(vector<double> ar1, vector<double> ar2)
        {
            double x = 0;
            double y = 0;
            double z = 0;
            for (int i = 0; i < ar1.size(); i ++)
            {
                x += ar1[i]*ar2[i];
                y += ar1[i]*ar1[i];
                z += ar2[i]*ar2[i];
            }
            x = x/(sqrt(y)*sqrt(z));
            return x;
        }

        vector<vector<double>> form_similarity_matrix(int n)
        {
            vector<vector<double>> num_vec = delete_n(n);
            int size1 = num_vec.size();
            vector<vector<double>> similarity_matrix(size1,vector<double>(size1) );
            for (int i = 0; i < num_vec.size(); i ++)
            {
                for (int j = 0; j < num_vec.size(); j ++)
                {
                    similarity_matrix[i][j] = compute_similarity(num_vec[i], num_vec[j]);
                }
            }
            return similarity_matrix;
        }

        vector<int> random_generator(int k, int n)
        {
            vector<int> random_ar;
            vector<int> check_ar;
            vector<int>::iterator it;
            while (k > 0)
            {
                int a = rand()%(records_ar.size()-n);
                it = find(random_ar.begin(), random_ar.end(), a);
                if (it == random_ar.end())
                {
                    random_ar.push_back(a);
                    k = k - 1;
                }
            }
            return random_ar;
        }
        
        vector<double> updated_id(int k, int n)
        {
            vector<vector<double>> similarity_matrix = form_similarity_matrix(n);
            vector<int> random_ar = random_generator(k, n);
            vector<double> id_ar;
            for (int i = 0; i < records_ar.size(); i ++)
            {
                id_ar.push_back(-1);
            }
            int x = 1;
            for (int i = 0; i < k; i ++)
            {
                id_ar[random_ar[i]] = x;
                x++;
            }
            for (int i = 0; i < records_ar.size(); i ++)
            {
                vector<double> temp;
                for (int j = 0; j < random_ar.size(); j ++)
                {
                    if (id_ar[i] == -1)
                        temp.push_back(similarity_matrix[i][j]);
                }
                int min_index = 0;
                for (int k = 0; k < temp.size(); k ++)
                {
                    if (temp[k] < temp[min_index])
                        min_index = k;
                }
                id_ar[i] = min_index + 1;
            }
            return id_ar;
        }

        void output1(int k, int n)
        {
            vector<double> id_ar = updated_id(k, n);
            
            for (int i = 0; i < records_ar.size(); i ++)
            {
                records_ar[i].addElement(to_string((int)id_ar[i]));
            }
            output_record_to_csv(records_ar,"Updated Records.csv");
        }

        void output2(int k, int n)
        {
            vector<double> id_ar = updated_id(k, n);
            int size = records_ar.size();
            Matrix final_ar(size,size);
            
            for (int i = 0; i < records_ar.size(); i ++)
            {
                for (int j = 0; j < records_ar.size(); j ++)
                {
                    if (id_ar[i] == id_ar[j])
                    {
                        final_ar.setElement(i,j,1);
                    }
                    else
                    {
                        final_ar.setElement(i,j,0);
                    }
                }
            }
            // return final_ar;
            final_ar.output_to_csv("SimilarID.csv");
        }


        //getters
        vector<Record> get_record_ar()
        {
            return records_ar;
        }
};

#endif