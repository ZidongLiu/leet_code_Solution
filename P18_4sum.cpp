//
// Created by Zidong Liu on 6/1/18.
//
#include <vector>
#include <algorithm>
/// 16ms solution, beats 95%
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret_list;
        if(nums.size()<4){
            return(ret_list);
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int a=0;a<n-3;++a){
            if(nums[a]==nums[a-1]&&a!=0){
                continue;
            }
            if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3]>target){
                break;
            }
            if(nums[a]+nums[n-3]+nums[n-2]+nums[n-1]<target){
                continue;
            }
            for(int b=a+1;b<n-2;++b){
                if(nums[b]==nums[b-1]&&b!=a+1){
                    continue;
                }
                if(nums[a]+nums[b]+nums[b+1]+nums[b+2]>target){
                    break;
                }
                if(nums[a]+nums[b]+nums[n-2]+nums[n-1]<target){
                    continue;
                }
                int front = b+1, back = nums.size()-1;
                int this_target = target - nums[a] - nums[b];
                while(front<back){
                    if(nums[front]==nums[front-1]&&front!=b+1){
                        ++front;
                        continue;
                    }
                    if(nums[back]==nums[back+1]&&back!=nums.size()-1){
                        --back;
                        continue;
                    }
                    int this_sum = nums[front]+nums[back];
                    if(this_sum<this_target){
                        ++front;
                    }else if(this_sum>this_target){
                        --back;
                    }else{
                        ret_list.push_back({nums[a],nums[b],nums[front],nums[back]});
                        ++front;
                        --back;
                    }
                }

            }
        }
        return(ret_list);
    }
};