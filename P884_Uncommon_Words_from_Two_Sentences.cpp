//
// Created by Zidong Liu on 8/18/18.
//
#include <string>
#include <map>
#include <vector>
using namespace std;
///////// 0ms, beat 100%
///////// median solution

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> string_a, string_b, ret_str;
        int n_a = A.length(), n_b = B.length();
        if(n_a==0&&n_b==0){
            return(string_a);
        }else{
            string::iterator itr_A = A.begin(), itr_B = B.begin();
            string new_str;
            map<string,int> check_map;
            while(itr_A!=A.end()){
                if(*itr_A!=' '){
                    new_str.push_back(*itr_A);
                }else{
                    string_a.push_back(new_str);
                    new_str.clear();
                }
                itr_A++;
            }
            if(new_str.size()>0){
                string_a.push_back(new_str);
                new_str.clear();
            }

            while(itr_B!=B.end()){
                if(*itr_B!=' '){
                    new_str.push_back(*itr_B);
                }else{
                    string_b.push_back(new_str);
                    new_str.clear();
                }
                itr_B++;
            }
            if(new_str.size()>0){
                string_b.push_back(new_str);
            }

            for(string elem: string_a){
                auto ret_ite = check_map.find(elem);
                if(ret_ite==check_map.end()){
                    check_map.insert({elem,1});
                }else{
                    ret_ite->second++;
                }
            }
            for(string elem: string_b){
                auto ret_ite = check_map.find(elem);
                if(ret_ite==check_map.end()){
                    check_map.insert({elem,1});
                }else{
                    ret_ite->second++;
                }
            }
            for(auto elem:check_map){
                if(elem.second==1){
                    ret_str.push_back(elem.first);
                }

            }
            return(ret_str);
        }

    }
};