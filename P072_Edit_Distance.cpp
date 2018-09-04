//
// Created by Zidong Liu on 8/26/18.
//
#include <string>
#include <vector>
using namespace std;
/////// good solution, beat 90%
/////// 8ms
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if(m==0||n==0){
            return(max(m,n));
        }else{
            vector<int> row(n,0);
            vector<vector<int>> dp(m,row);
            int ind_row =1;
            for(int i=0;i<n;i++){
                if(word1[0]==word2[i]){
                    ind_row = 0;
                }
                dp[0][i] = i+ind_row;
            }
            int ind_col =1;
            for(int i=0;i<m;i++){
                if(word1[i]==word2[0]){
                    ind_col=0;
                }
                dp[i][0] = i+ind_col;
            }
            for(int i=1;i<m;i++){
                ///cout<<"word1: "<<word1[i]<<endl;
                for(int j=1;j<n;j++){
                    ///cout<<"word2: "<<word2[j]<<endl;
                    if(word1[i]==word2[j]){
                        ///cout<<"here"<<endl;
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]) +1;
                    }
                }
            }
            /*
            for(auto elem:dp){
                for(auto elem1:elem){
                    cout<<setw(4)<<elem1;
                }
                cout<<endl;
            }
             */
            return(dp[m-1][n-1]);
        }
    }
};