//
// Created by Zidong Liu on 5/27/18.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ret_str(numRows);
        int period = (2*numRows-2);
        if(period==0){
            return s;
        }
        int cur;
        for(int i=0;i<s.length();i++){
            cur = i%period;
            if(cur<numRows){
                ret_str[cur].push_back(s[i]);
            }else{
                cur = period - cur;
                ret_str[cur].push_back(s[i]);
            }
        }
        string ret={""};
        for(auto elem: ret_str){
            ret += elem;
        }
        return(ret);
    }
};
