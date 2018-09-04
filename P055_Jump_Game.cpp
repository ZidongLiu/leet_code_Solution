//
// Created by Zidong Liu on 8/21/18.
//
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
/////////// recursive method tle, waste
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int cur_ind = 0;
        bool ret_bool=0;
        nextstep(n,nums,cur_ind,ret_bool);
        return(ret_bool);
    }

    void nextstep(int &n, vector<int> &nums, int cur_ind, bool &ret_bool){
        if(cur_ind+nums[cur_ind]>=n-1){
            ret_bool =1;
        }else{
            for(int j= cur_ind+1;j <= cur_ind+nums[cur_ind];j++){
                nextstep(n,nums,j,ret_bool);
            }
        }
    }
};

////// dp, tle

class Solution2{
public:
    bool canJump(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n-1,0);
        for(int i = n-2;i>=0;i--){
            if(i+nums[i]>=n-1){
                dp[i] = 1;
            }else{
                for(int j=i+1;j<=i+nums[i];j++){
                    if(dp[j]==1){
                        dp[i]==1;
                        break;
                    }
                }
            }
        }
        return(dp[0]);

    }
};

////// 1 pass, try to think a better way to solve problem

class Solution3{
public:
    bool canJump(vector<int> &nums){
        int max_reach = 0;
        for(int i =0;i<nums.size() && max_reach>=i; i++){
            max_reach = max(max_reach,i+nums[i]);
        }
        return(max_reach>=nums.size()-1);
    }
};
