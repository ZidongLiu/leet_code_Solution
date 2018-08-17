//
// Created by Zidong Liu on 6/4/18.
//
#include <string>
#include <algorithm>
using namespace std;

// 7ms, beat 78.83%
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return(0);
        }
        int n = haystack.length(),k=needle.length(),idx=-1;
        if(n<k){
            return(idx);
        }
        int f = haystack.find(needle);
        if(f>=n||f<0){
            return(idx);
        }else{
            return(f);
        }
    }
};