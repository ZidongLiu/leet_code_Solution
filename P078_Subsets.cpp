//
// Created by Zidong Liu on 8/27/18.
//
#include <vector>
using namespace std;
/////// medium solution
/////// beat 100%

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retvec;
        if(nums.size()==0){
            retvec.push_back({});
            return(retvec);
        }else{
            vector<int> this_vec;
            retvec.push_back({});
            int k=0, n =nums.size();
            fly(this_vec,n, 0,nums,retvec);
        }
        return(retvec);
    }
    void fly(vector<int> this_vec, int &n, int k, vector<int> &nums, vector<vector<int>> &retvec){
        if(k==n){
            return;
        }else{
            fly(this_vec,n,k+1,nums,retvec);
            this_vec.push_back(nums[k]);
            retvec.push_back(this_vec);
            fly(this_vec,n,k+1,nums,retvec);
        }
    }
};