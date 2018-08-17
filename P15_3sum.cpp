//
// Created by Zidong Liu on 6/1/18.
//
/*       bad solution
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        /// get a sorted nums
        vector<int> sort_nums = nums;
        sort(sort_nums.begin(),sort_nums.end());
        /// get a valid unique sorted nums
        vector<int> unique_nums = sort_nums;
        vector<int>::iterator end = unique(unique_nums.begin(),unique_nums.end());
        unique_nums.erase(end,unique_nums.end());
        /// get reps for the unique nums
        vector<int> rep;
        int cur_rep = 1;
        for(vector<int>::iterator i=sort_nums.begin(); i!=sort_nums.end(); ++i){
            if(*i==*(i+1)){
                ++cur_rep;
            }else{
                rep.push_back(cur_rep);
                cur_rep =1;
            }
        }
        /// search for 0
        map<int,int> map_num_rep;
        for(int i=0;i<unique_nums.size();i++){
            map_num_rep[unique_nums[i]] = rep[i];
        }
        /// search for 0
        if(map_num_rep.find(0)->second>=3){
            ret_vec.push_back({0,0,0});
        }
        /// search for 2 rep and 1 other
        for(auto i = map_num_rep.begin();i!=map_num_rep.end();++i){
            if(i->second>=2){
                int require = -2*(i->first);
                if(binary_search(unique_nums.begin(),unique_nums.end(),require)){
                    ret_vec.push_back({i->first,i->first,require});
                }
            }
        }
        /// search for 1 rep
        for(int i=0;i<unique_nums.size()-2;i++){
            for(int j=i+1;j<unique_nums.size()-1;j++){
                int require = -(unique_nums[i]+unique_nums[j]);
                if(find(unique_nums.begin()+j+1,unique_nums.end(),require)!=unique_nums.end()){
                    ret_vec.push_back({unique_nums[i],unique_nums[j],require});
                }
            }
        }
        return(ret_vec);
    }

    void printSolution(vector<vector<int>> &a){
        for(int i=0;i<a.size();i++){
            for(auto elem: a[i]){
                cout<<elem<<"  ";
            }
            cout<<endl;
        }
    }
};

*/

//   n^2 method, beat 50%
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        if(nums.size()<3) {
            return (ret_vec);
        }
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;++i) {
            if(nums[i]==nums[i-1]&&(i!=0)){
                continue;/// break the i loop when the two numbers ar the same
            }
            int target = -nums[i], front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target) {
                    ++front;
                } else if (sum > target) {
                    --back;
                } else {
                    if(nums[front]==nums[front-1]&&(front!=i+1)){
                        ++front;
                        continue;
                    }
                    if(nums[back]==nums[back+1]&&(back!=nums.size()-1)){
                        --back;
                        continue;
                    }
                    ret_vec.push_back({nums[i],nums[front],nums[back]});
                    ++front;
                    --back;
                }
            }
        }
        return(ret_vec);
    }
};
