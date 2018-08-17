//
// Created by Zidong Liu on 8/15/18.
//

//////// 8 ms
//////// beat 99.69%

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> this_vec;
        vector<vector<int>> ret_vec;
        int ind=0, sum=0;
        gotonext(this_vec,ind,sum,candidates,target,ret_vec);
        return(ret_vec);
    }

    void gotonext(vector<int> this_vec, int ind, int sum, vector<int> &candidates, int target, vector<vector<int>> &ret_vec){
        int n = candidates.size();
        for(int i=ind; i < n; i++){
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