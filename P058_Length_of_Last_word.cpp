//
// Created by Zidong Liu on 8/22/18.
//
//// lower than medium solution
//// beat 30%

#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        if(n==0){
            return(0);
        }else{
            while(s[n]== ' ' && n>=0){
                n--;
            }
            if(n==-1){
                return(0);
            }else{
                int ret_val = 0;
                while(s[n] != ' ' && n>=0){
                    n--;
                    ret_val++;
                }
                return(ret_val);
            }
        }
    }
};