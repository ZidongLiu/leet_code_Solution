//
// Created by Zidong Liu on 9/3/18.
//
#include <string>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K>1){
            sort(S.begin(),S.end());
            return(S);
        }else{
            int l = S.length();
            string cur = S;
            for(int i=0;i<l;i++){
                if(S.substr(i,l-i)+S.substr(0,i) < cur){
                    cur = S.substr(i,l-i)+S.substr(0,i);
                }
            }
            return(cur);
        }
    }
};