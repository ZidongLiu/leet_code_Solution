//
// Created by Zidong Liu on 6/4/18.
//
/*
 *
 * slow solution, beat 5%, 140ms
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),i;
        if(n==0){
            return(0);
        }
        if(n==1){
            return(1);
        }
        i = n-1;
        int num=0;
        while(i>=0){
            int k=1;
            while(nums[i]==nums[i-1]&&i>=1){
                --i;
                ++k;
            }
            if(k==1){
                --i;
                ++num;
                continue;
            }else{
                for(int j=1;j<=num;++j){
                    nums[i+j] = nums[i+k+j-1];
                }
            }
            --i;
            ++num;
        }
        return(num);
    }
};

 */
// 28ms, beats 97%
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return(n);
        }
        int i=0;
        for(int j=1;j<n;++j){
            if(nums[i]!=nums[j]){
                nums[++i] = nums[j];
            }
        }
        nums.erase(nums.begin()+i+1,nums.end());
        return(i+1);
    }
};