//
// Created by Zidong Liu on 9/3/18.
//
#include <string>
#include <vector>
using namespace std;


//////// beat 100%

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length();
        if(m==0){
            return(s2==s3);
        }
        if(n==0){
            return(s1==s3);
        }
        vector<bool> row(n+1,0);
        vector<vector<bool>> dp(m+1,row);
        dp[0][0]=1;

        for(int i=1;i<=m;i++){
            if(dp[i-1][0]){
                dp[i][0] = (s1[i-1]==s3[i-1]);
            }
        }

        for(int j=1;j<=n;j++){
            if(dp[0][j-1]){
                dp[0][j] = (s2[j-1]==s3[j-1]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if((dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1])){
                    dp[i][j]=1;
                }
            }
        }

        return(dp[m][n]);
    }
};