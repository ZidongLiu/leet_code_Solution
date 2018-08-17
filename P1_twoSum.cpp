
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_ind;
        int dif;
        int j;

        for(int i =0;i<nums.size();i++){
            num_ind.insert({nums[i],i});
        }

        for(int i=0;i<nums.size();i++){
            dif = target - nums[i];
            auto ret_ite = num_ind.find(dif);
            if(ret_ite!=num_ind.end()&&ret_ite->second!=i){
                vector<int> ret={i,ret_ite->second};
                return ret;
            }
        }

    }
};


