//
// Created by Zidong Liu on 8/17/18.
//
#include <vector>
#include <string>
#include <map>

using namespace std;
////// solution could be refined by assigning int index for the strs
////// 28ms, beat 30%

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ret_map;
        vector<vector<string>> ret_str;
        for(auto elem:strs){
            string a(elem);
            sort(a.begin(),a.end());
            ret_map[a].push_back(elem);
        }
        for(map<string,vector<string>>::iterator itr= ret_map.begin(); itr!=ret_map.end();itr++){
            ret_str.push_back(itr->second);
        }
        return(ret_str);
    }
};
