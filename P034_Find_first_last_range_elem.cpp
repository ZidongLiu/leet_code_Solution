//
// Created by Zidong Liu on 8/14/18.
//
///// first find an element of target
///// then find left and right
///// beat 100%
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==target){
                return(vector<int>({0,0}));
            }
        }else if(n==2){
            int id = distance(nums.begin(),find(nums.begin(),nums.end(),target));
            if(id==0){
                if(nums[1]==target){
                    return(vector<int>({0,1}));
                }else{
                    return(vector<int>({0,0}));
                }
            }else if(id ==1){
                return(vector<int>({1,1}));
            }
        }else if(n>2){ /// start bisection search
            int mid, left= 0, right = n-1, ind=0;
            int left_left, left_right, right_left, right_right, right_most, left_most, left_mid, right_mid;
            while(left < right){
                mid = (left+right)/2;
                if(nums[mid]<target){
                    left = mid +1;
                }else if(nums[mid]>target){
                    right = mid;
                }else{
                    ind = 1;
                    left_left = left;
                    left_right = mid;
                    right_right = right;
                    right_left = mid;
                    break;
                }

            }
            if(nums[left]==target&&ind==0){
                return(vector<int>({left,right}));

            }
            if(ind == 1){
                /// left_most
                while(1){
                    left_mid = (left_left+left_right)/2;

                    if(nums[left_mid] < target){
                        left_left = left_mid +1;
                    }else if(left_mid>0 && nums[left_mid-1]==target){
                        left_right = left_mid;
                    }else{
                        left_most = left_mid;
                        break;
                    }
                }

                /// right_most
                while(1){
                    right_mid = (right_left+right_right)/2;

                    if(nums[right_mid]>target){
                        right_right = right_mid;
                    }else if((right_mid < n-1) && nums[right_mid+1]==target){
                        right_left = right_mid+1;
                    }else{
                        right_most = right_mid;
                        break;
                    }
                }
                return(vector<int>({left_most,right_most}));
            }

        }
        return(vector<int>({-1,-1}));
    }
};

