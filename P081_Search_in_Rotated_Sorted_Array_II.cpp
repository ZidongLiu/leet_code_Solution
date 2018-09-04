//
// Created by Zidong Liu on 8/28/18.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/////// 28ms, bad solution
/////// idea is OK
/*
 * case study : pair (mid, target)
 * (1,1), mid<target, left = mid+1
 * (1,1), mid>target, right = mid
 * (2,2), mid<target, left = mid+1
 * (2,2), mid>target, right = mid
 * (1,2), mid>target, left = mid+1
 * (2,1), mid<target, right = mid
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return(0);
        }
        int left = 0, right = nums.size()-1, mid=0;
        if(target < nums.back()){ //// target in 2, case 3,4,5
            while(left<right){
                mid = (left+right)/2;
                cout<<"left: "<<left<<"   mid: "<<mid<<"  right: "<<right<<endl;
                if(nums[mid]==target){
                    return(1);
                }else if(nums[mid]<target){ //// case 3, (2,2)
                    ///cout<<"case:3"<<endl;
                    left = mid + 1;
                }else{ ///// case 4,5

                    if(nums[mid] < nums[right]){ /// case 4
                        right =mid;
                    }else if(nums[mid] >nums[right]){ /// case 5
                        left = mid+1;
                    }else{ /// can not know which side is mid, but nums[right] > target, and right should always be in 2
                        right--;
                    }
                }
            }
        }else if(target>nums.back()){ //// target in 1, case 1,2,6, left should always be in left part
            ///cout<<"here"<<endl;
            while(left<right){

                mid = (left+right)/2;
                cout<<"left: "<<left<<"   mid: "<<mid<<"  right: "<<right<<endl;
                if(nums[mid] == target){
                    return(1);
                }else if(nums[mid]<target){/////// case case 1,6
                    if(nums[mid] < nums[left]){  ///// case 6
                        right = mid;
                    }else if(nums[mid] > nums[left]){ //// case 1
                        left = mid+1;
                    }else{ //// can not determine which side is mid, but left should always be in region 1
                        left++;
                    }
                }else{ ////// case 2
                    right = mid;
                }
            }
        }else{
            return(1);
        }

        return(nums[left]==target||nums[right]==target);
    }
};