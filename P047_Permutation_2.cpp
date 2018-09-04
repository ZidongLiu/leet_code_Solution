//
// Created by Zidong Liu on 8/17/18.
//
#include <vector>
#include <algorithm>
using namespace std;
/////////////////// Solution 1, use function nextPermutation
/////////////////// beat 99.62%, 16ms

class Solution1 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret_vec;
        vector<int> start(nums);
        ret_vec.push_back(nums);
        nextPermutation(nums);
        while(!equal(nums.begin(),nums.end(),start.begin())){
            ret_vec.push_back(nums);
            nextPermutation(nums);
        }
        return(ret_vec);
    }

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


////////// recursion
///////// slower than next_permutation version, might be from the erase operation,
///////// 28ms, beat 20%

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        work_on_fly(cur,nums,ret_vec);
        return(ret_vec);
    }

    void work_on_fly(vector<int> &cur, vector<int> &left_num, vector<vector<int>> &ret_vec){
        for(int i=0;i<left_num.size();i++){
            if((i>0&&left_num[i]!=left_num[i-1])||i==0){
                vector<int> a(cur), b(left_num);
                a.push_back(left_num[i]);
                b.erase(b.begin(),b.begin()+i);
                if(b.size()==0){
                    ret_vec.push_back(a);
                }else{
                    work_on_fly(a,b,ret_vec);
                }
            }
        }
    }
};