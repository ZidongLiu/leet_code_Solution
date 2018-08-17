//
// Created by Zidong Liu on 6/5/18.
//
#include <vector>
#include <algorithm>
using namespace std;
/// 16ms, beat 65%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(nums[i-1]>=nums[i]&&i>=1){/// find the element
            --i;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
        }else{
            int j = nums.size()-1;
            while(nums[j]<=nums[i-1]){
                --j;
            }
            int temp = nums[j]; // change the order
            nums[j] = nums[i-1];
            nums[i-1] = temp;
            reverse(nums.begin()+i,nums.end());
        }
    }
};