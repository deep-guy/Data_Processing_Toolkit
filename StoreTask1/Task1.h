#ifndef Task1_H_
#define Task1_H_

#include <bits/stdc++.h>
#include "Record.h"
using namespace std;
class Task1
{
    private:
        vector<Record> records_ar;
    public:
        Task1();
        Task1(vector<Record> records_ar1);
        ~Task1();
        Task1(const Record&);
        vector<vector<double>> delete_n(int n)
        {
            vector<Record> temp = records_ar;
            for (int i = 0; i < records_ar.size(); i ++)
            {
                temp[i].get_record_ar().erase(temp[i].get_record_ar().begin(), temp[i].get_record_ar().begin()+(temp[i].get_record_ar().size()-n));
            }
            vector<vector<double>> double_ar;
            vector<vector<double>> similarity_matrix;
            for (int i = 0; i < temp.size(); i ++)
            {
                for (int j = 0; j < n; j ++)
                    double_ar[i].push_back(0.00);
            }
            for (int i = 0; i < temp.size(); i ++)
            {
                for (int j = 0; j < n; j ++)
                {
                    double_ar[i].push_back(stod(temp[i].get_record_ar()[j])); 
                }
            }
            return double_ar;
        }
        
        double compute_similarity(vector<double> ar1, vector<double> ar2)
        {
            double x = 0;
            for (int i = 0; i < ar1.size(); i ++)
            {
                x += ar1[i]*ar2[i];
            }
            return x;
        }

        vector<vector<double>> form_similarity_matrix(int n)
        {
            vector<vector<double>> num_vec = delete_n(n);
            vector<vector<double>> similarity_matrix;
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
            // for (int i = 0; i < records_ar.size(); i ++)
            //     check_ar.push_back(-1);
            vector<int>::iterator it;
            // int x = 1;
            while (k > 0)
            {
                int a = rand()%n;
                it = find(random_ar.begin(), random_ar.end(), a);
                if (it == random_ar.end())
                {
                    random_ar.push_back(a);
                    // check_ar[a] = x;
                    // x = x + 1;
                    k = k - 1;
                }
            }
            return random_ar;
        }
        
        vector<int> updated_id(int k, int n)
        {
            vector<vector<double>> similarity_matrix = form_similarity_matrix(n);
            vector<int> random_ar = random_generator(k, n);
            vector<int> id_ar;
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

        vector<Record> output1(int k, int n)
        {
            vector<int> id_ar = updated_id(k, n);
            for (int i = 0; i < records_ar.size(); i ++)
            {
                records_ar[i].get_record_ar.push_back(to_string(id_ar[i]));
            }
            return records_ar;
        }

        vector<vector<int>> output2(int k, int n)
        {
            vector<int> id_ar = updated_id(k, n);
            vector<vector<int>> final_ar;
            for (int i = 0; i < records_ar.size(); i ++)
            {
                for (int j = 0; j < records_ar.size(); j ++)
                {
                    if (id_ar[i] == id_ar[j])
                    {
                        final_ar[i][j] = 1;
                    }
                    else
                    {
                        final_ar[i][j] = 0;
                    }
                }
            }
            return final_ar;
        }


        //getters
        vector<Record> get_record_ar()
        {
            return records_ar;
        }
};

#endif