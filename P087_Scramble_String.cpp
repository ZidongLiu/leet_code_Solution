//
// Created by Zidong Liu on 8/30/18.
//
#include <string>
#include <vector>
using namespace std;
///////// recursion fails becasue the partition is not in the middle
class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return(0);
        }else{
            int n = s1.length();
            if(n==1){
                return(s1[0]==s2[0]);
            }else if(n%2==1){
                string s1_left_1,s1_left_2, s1_right_1,s1_right_2;
                string s2_left, s2_right;
                s1_left_1 = s1.substr(0,n/2);
                s1_right_1 = s1.substr(n/2);
                s1_left_2 = s1.substr(0,n/2+1);
                s1_right_2 = s1.substr(n/2+1);
                s2_left = s2.substr(0,n/2);
                s2_right = s2.substr(n/2);
                return( (isScramble(s1_left_1,s2_left)&&isScramble(s1_right_1,s2_right)) || (isScramble(s1_left_2,s2_right) && isScramble(s1_right_2,s2_left)));
            }else{
                string s1_left, s1_right, s2_left, s2_right;
                s1_left = s1.substr(0,n/2);
                s1_right = s1.substr(n/2);
                s2_left = s2.substr(0,n/2);
                s2_right = s2.substr(n/2);
                return((isScramble(s1_left,s2_left)&&isScramble(s1_right,s2_right)) ||(isScramble(s1_left,s2_right)&&isScramble(s1_right,s2_left)));
            }
        }
    }
};

///////////////////// dynamic programming
//////////////////// beat 2%

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(n==0){
            return(1);
        }
        vector<bool> d1(n,0);
        vector<vector<bool>> d2(n,d1);
        vector<vector<vector<bool>>> d3(n,d2);
        vector<vector<vector<vector<bool>>>> dp(n,d3);
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=n-1;j++){
                if(s1[i]==s2[j]){
                    dp[i][i][j][j]=1;
                }
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                for(int j=0;j<=n-l;j++){
                    bool this_val =0;
                    for(int k=1;k<l;k++){
                        this_val = this_val || (dp[i][i+k-1][j][j+k-1] && dp[i+k][i+l-1][j+k][j+l-1]) || (dp[i][i+k-1][j+l-k][j+l-1] && dp[i+k][i+l-1][j][j+l-k-1]);
                        if(this_val==1){
                            break;
                        }
                    }
                    dp[i][i+l-1][j][j+l-1] = this_val;
                }
            }
        }
        return(dp[0][n-1][0][n-1]);
    }
};