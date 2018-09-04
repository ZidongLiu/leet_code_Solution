//
// Created by Zidong Liu on 8/15/18.
//
///////// 4ms
///////// beat 100%


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret_vec;
        vector<int> this_vec;
        int ind =0, sum =0;
        sort(candidates.begin(),candidates.end());
        gotonext(this_vec,ind, sum, candidates, target, ret_vec);
        return(ret_vec);
    }

    void gotonext(vector<int> this_vec, int ind, int sum, vector<int> &candidates, int target, vector<vector<int>> &ret_vec){
        int n = candidates.size();
        for(int i=ind+1; i < n; i++){
            if(sum+candidates[i]<target){
                vector<int> new_vec = this_vec;
                new_vec.push_back(candidates[i]);
                gotonext(new_vec,i, sum+candidates[i], candidates, target, ret_vec);
            }else if(sum+candidates[i]==target){
                vector<int> new_vec = this_vec;
                new_vec.push_back(candidates[i]);
                ret_vec.push_back(new_vec);
            }
        }
    }
};