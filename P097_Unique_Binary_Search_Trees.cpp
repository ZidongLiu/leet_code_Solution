//
// Created by Zidong Liu on 9/3/18.
//
#include <vector>
using namespace std;
/////// beat 100%
/////// medium solution

class Solution {
public:
    int numTrees(int n) {
        if(n==0){
            return(0);
        }
        vector<int> row(n,0);
        vector<vector<int>> dp(n,row);
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int l=1;l<=n-1;l++){
            for(int i=0;i <=n-1-l;i++){
                int this_val =  dp[i+1][i+l] + dp[i][i+l-1];
                for(int k=i+1;k<=i+l-1;k++){
                    this_val+= dp[i][k-1] * dp[k+1][i+l];
                }
                //cout<<this_val<<endl;
                dp[i][i+l] = this_val;
            }
        }

        return(dp[0][n-1]);
    }
};