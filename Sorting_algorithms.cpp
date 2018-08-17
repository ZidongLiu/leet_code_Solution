//
// Created by Zidong Liu on 8/16/18.
//

#include <vector>

using namespace std;

class Sorting_algorithm{
public:
    vector<int> merge_sort(vector<int> inp){
        int n = inp.size();
        int left = 0, right = n-1;
        int mid = (left+right)/2;

        vector<int> left_half, right_half;
        if(left<mid){
            copy(inp.begin(),inp.begin()+mid+1,back_inserter(left_half));
            left_half = merge_sort(left_half);
        }else{
            left_half.push_back(inp[0]);
        }
        if(right>mid+1){
            copy(inp.begin()+mid+1,inp.end(),back_inserter(right_half));
            right_half = merge_sort(right_half);
        }else{
            right_half.push_back(inp[n-1]);
        }

        return(merge(left_half,right_half));
    }


    vector<int> merge(vector<int> left_half, vector<int> right_half){
        int n1 = left_half.size(), n2 = right_half.size();
        int n_upper = n1+n2;
        vector<int> ret_vec(n_upper);
        int i_l = 0, i_r = 0;

        for(int k=0;k<n_upper;k++){
            if(i_l>=n1){
                ret_vec[k] = right_half[i_r++];
                continue;
            }
            if(i_r>=n2){
                ret_vec[k] = left_half[i_l++];
                continue;
            }
            if(left_half[i_l]<right_half[i_r]){
                ret_vec[k] = left_half[i_l++];
            }else{
                ret_vec[k] = right_half[i_r++];
            }
        }


        return(ret_vec);
    }
};