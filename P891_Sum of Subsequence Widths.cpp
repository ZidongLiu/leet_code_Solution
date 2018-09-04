//
// Created by Zidong Liu on 8/19/18.
//


//////// unsolved yet
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int ret=0, mod = 1e9 +7;
        int this_wid;
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                this_wid = (A[j]-A[i]) * pow(2,j-i);
                ret += this_wid%mod;
                ret %=mod;
            }
        }
        return(ret);
    }
};