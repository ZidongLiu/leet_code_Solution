//
// Created by Zidong Liu on 8/15/18.
//

////// median algorithm
////// 4ms, beat 80%

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return(1);
        }


        for(int i=0;i < n;i++){
            if(nums[i]>0 && nums[i] < n+1 && (nums[i]!=nums[nums[i]-1])){
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }

        for(int i=0; i<n+1; i++){
            if(nums[i]!=(i+1)){
                return(i+1);
            }
        }
        return(1);
    }
};

