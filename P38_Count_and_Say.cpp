//
// Created by Zidong Liu on 8/15/18.
//
/// 0ms,
/// beat100%


#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s0 = "1";
        if(n==1){
            return(s0);
        }else{
            for(int i=1;i<n;i++){
                s0 = para(s0);
            }
        }
        return(s0);
    }

    string para(string in_str){
        string ret_vec;
        int i=1, n = in_str.length();
        int count = 1;
        char this_one = in_str[0];
        ///cout<<"i: "<<i<<"  n: "<<n<<"  count: "<<count<<"  this_one: "<<this_one<<endl;
        while(i<n){
            if(this_one==in_str[i]){
                count++;
            }else{
                ret_vec.push_back('0'+count);
                ret_vec.push_back(this_one);
                this_one = in_str[i];
                count = 1;
            }
            i++;
        }
        ret_vec.push_back('0'+count);
        ret_vec.push_back(this_one);

        return(ret_vec);
    }
};