//
// Created by Zidong Liu on 8/21/18.
//

#include <vector>
#include <cmath>
using namespace std;
///// time limit exceed
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        int max = nums[0];
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
            if(dp[i][i]>max){
                max = dp[i][i];
            }
            for(int j=i+1;j<n;j++){
                dp[i][j] = dp[i][j-1] + nums[j];
                if(dp[i][j]>max){
                    max = dp[i][j];
                }
            }
        }
        return(max);
    }
};


///// at most O(n), the solution should be considered

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int lastSum = 0, max_sum = -pow(2,31);
        for(int i=0;i<n;i++){
            lastSum = max(lastSum+nums[i],nums[i]);
            if(lastSum>max_sum){
                max_sum=lastSum;
            }
        }
        return(max_sum);
    }
};

//// recursively solution, not good, really bad
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return(-pow(2,31));
        }
        int n = nums.size();
        int dp[2][n];
        int max_right = nums[0], right_ind = 0, max_left = nums[n-1], left_ind = n-1;
        dp[0][0] = nums[0];
        dp[1][n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            dp[0][i] = dp[0][i-1] + nums[i];
            if(dp[0][i]>=max_right){
                max_right = dp[0][i];
                right_ind = i;
            }
        }

        for(int j=n-2;j>=0;j--){
            dp[1][j] = dp[1][j+1] + nums[j];
            if(dp[1][j]>=max_left){
                max_left = dp[1][j];
                left_ind = j;
            }
        }
        ///cout<<"left: "<<left_ind<<"right: "<<right_ind<<endl;
        int max_elem = 0;
        if(left_ind<=right_ind){
            for(int i=left_ind;i<=right_ind;i++){
                max_elem += nums[i];
            }
            return(max_elem);
        }else{
            vector<int> left_part, right_part, mid_part;
            for(int i=0;i<=right_ind;i++){
                left_part.push_back(nums[i]);
            }
            for(int j=left_ind;j<n;j++){
                right_part.push_back(nums[j]);
            }
            for(int i=right_ind+1;i<left_ind;i++){
                mid_part.push_back(nums[i]);
            }
            max_elem = max(max(maxSubArray(left_part),maxSubArray(right_part)),maxSubArray(mid_part));
            return(max_elem);
        }
    }
};
