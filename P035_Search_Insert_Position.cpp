//
// Created by Zidong Liu on 8/15/18.
//

/// median solution, beat 98%
/// 4ms

#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0){
            return(0);
        }else if(n<5){
            if(target<=nums[0]){
                return(0);
            }
            if(target>nums[n-1]){
                return(n);
            }
            for(int k = 0  ;k < n-1;k++){
                if(nums[k]<target&&target<=nums[k+1]){
                    return(k+1);
                }
            }
        }else{
            int left=0, right=n-1, mid;
            while(1){
                mid = (left+right)/2;
                if(nums[mid]<target){
                    if(mid==n-1){
                        return(n);
                    }else if(nums[mid+1]>target){
                        return(mid+1);
                    }else{
                        left = mid+1;
                    }
                }else if(nums[mid]>target){
                    if(mid==0){
                        return(0);
                    }else if(nums[mid-1]<target){
                        return(mid);
                    }else{
                        right = mid;
                    }
                }else{
                    return(mid);
                }
            }
        }
        return(-1);
    }
};


