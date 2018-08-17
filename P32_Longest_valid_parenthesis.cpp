//
// Created by Zidong Liu on 6/5/18.
//

#include <string>
#include <vector>
using namespace std;
/// dynamic programming, be used to thinking in dynamic way
// 12ms, beat 81.9%
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(),max_len=0;
        if(n==0||n==1){
            return(0);
        }
        vector<int> dp(n);
        dp[0] = 0;
        if(s[0]=='('&&s[1]==')'){
            dp[1] = 2;
            max_len = 2;
        }else{
            dp[1] = 0;
        }
        for(int i=2; i<n ;++i){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = dp[i-2] + 2;
                    max_len = dp[i]>max_len?dp[i]:max_len;
                }else{
                    if(s[i-dp[i-1]-1]=='('){
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                        max_len = dp[i]>max_len?dp[i]:max_len;
                    }else{
                        dp[i] = 0;
                    }
                }
            }else{
                dp[i]=0;
            }
        }
        return(max_len);
    }
};

