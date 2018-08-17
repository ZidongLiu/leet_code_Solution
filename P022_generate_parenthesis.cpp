//
// Created by Zidong Liu on 6/3/18.
//
// great solution, back track, idea is to add possible parenthesis, note because no break or ret before the final string is get, the solution is OK
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        add_par(ret,"",n,0);
        return(ret);
    }

    void add_par(vector<string> &v, string str,int left,int right){
        if(left==0&&right==0){
            v.push_back(str);
            return;
        }
        if(left>0){
            add_par(v,str+"(",left-1,right+1);
        }
        if(right>0){
            add_par(v,str+")",left,right-1);
        }
    }
};
