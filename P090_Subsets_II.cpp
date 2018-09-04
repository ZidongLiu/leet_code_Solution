//
// Created by Zidong Liu on 9/1/18.
//
#include <vector>
#include <utility>
using namespace std;
///////////// 8ms
//////////// beat 34%

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        ret.push_back({});
        if(n==0){
            return(ret);
        }
        sort(nums.begin(),nums.end());
        vector<int> nums1,nums1_count;
        int this_start = nums[0], count = 1;
        nums1.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==this_start){
                count++;
            }else{
                nums1_count.push_back(count);
                nums1.push_back(nums[i]);
                this_start = nums[i];
                count = 1;
            }
        }
        nums1_count.push_back(count);
        /*
        for(auto elem:nums1){
            cout<<setw(4)<<elem;
        }
        cout<<endl;
        for(auto elem:nums1_count){
            cout<<setw(4)<<elem;
        }
        cout<<endl;
        */

        vector<int> a;
        helper(a,nums1,nums1_count, 0,ret);

        return(ret);

    }

    void helper(vector<int> &on_vec,  vector<int> &nums1, vector<int> &count, int ind, vector<vector<int>> &ret_vec){
        if(ind>=nums1.size()){
            return;
        }else{
            helper(on_vec,nums1,count,ind+1,ret_vec);
            on_vec.insert(on_vec.end(),count[ind],nums1[ind]);
            for(int i=count[ind];i>=1;i--){
                ret_vec.push_back(on_vec);
                helper(on_vec,nums1,count,ind+1,ret_vec);
                on_vec.pop_back();
            }
        }
    }
};