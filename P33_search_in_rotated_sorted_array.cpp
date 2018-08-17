//
// Created by Zidong Liu on 6/5/18.
//


//// 4ms, beat 98.40%

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INFINITY = 10000000;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=3){
            vector<int>::iterator itr = find(nums.begin(),nums.end(),target);
            if(itr>=nums.end()){
                return(-1);
            }else{
                return(distance(nums.begin(),itr));
            }
        }
        int low=0, high = n-1;

        while(low<high){
            int mid = (low+high)/2;
            int num;
            if((nums[mid]<nums[0])==(target<nums[0])){
                num = nums[mid];
            }else {
                if (target > nums[mid]) {
                    num = INFINITY;
                }else{
                    num = -INFINITY;
                }
            }
            cout<<"low: "<<low<<"  high: "<<high<<" mid: "<<mid<<"  num: "<<num<<endl;
            if(num>target){
                high = mid;
            }else if(num<target){
                low = mid+1;
            }else{
                return(mid);
            }
        }
        if(nums[low]==target){
            return(low);
        }
        return(-1);
    }
};