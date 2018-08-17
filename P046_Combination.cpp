//
// Created by Zidong Liu on 8/17/18.
//
#include <vector>
using namespace std;
//// back_track 8ms, beat 98%( median solution)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        vector<int> cur;
        work_on_fly(cur,nums, ret_vec);
        return(ret_vec);
    }
    void work_on_fly(vector<int> &cur_vec, vector<int> &ret_num, vector<vector<int>> &ret_vec){
        for(int i=0;i<ret_num.size();i++){
            vector<int> a(cur_vec);
            a.push_back(ret_num[i]);
            vector<int> b(ret_num);
            b.erase(b.begin()+i,b.begin()+i+1);
            if(b.size()==0){
                ret_vec.push_back(a);
            }else{
                work_on_fly(a,b,ret_vec);
            }
        }
    }
};