//
// Created by Zidong Liu on 8/14/18.
//


#include<vector>
///// solution using dp, no binary search
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return(n);
        }
        int cur_max_length;
        vector<int> dp;
        dp.push_back(1);
        for(int i=1;i<n;i++){
            cur_max_length = 1;
            for(int j=0;j<i;j++){
                if((nums[i]>nums[j])&&(dp[j]+1>cur_max_length)){
                    cur_max_length = dp[j] + 1;
                }
            }
            dp.push_back(cur_max_length);
        }
        return(*max_element(dp.begin(),dp.end()));
    }
};