//
// Created by Zidong Liu on 8/18/18.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret_str;
        for(auto elem: words){
            int ind =1;
            if(elem.length()==pattern.length()){
                for(int i=0;i<elem.length();i++){
                    for(int j=i+1;j<elem.length();j++){
                        if(!((elem[i]==elem[j])==(pattern[i]==pattern[j]))){
                            ind =0;
                            break;
                        }
                    }
                    if(ind==0){
                        break;
                    }
                }
                if(ind==1){
                    ret_str.push_back(elem);
                }
            }
        }


        return(ret_str);
    }
};