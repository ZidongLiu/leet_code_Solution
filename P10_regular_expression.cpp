//
// Created by Zidong Liu on 5/28/18.
//

//   recursive way of solving the problem

#include <string>
using namespace std;


/*
 *
 * recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()){
            return(s.empty());
        }
        if(p[1]=='*'){
            return(isMatch(s,p.substr(2))||(!s.empty())&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p));
        }else{
            return(!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1)));
        }
    }
};
*/


// dynamic programming

class Solution2 {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return(s.empty());

        int m = s.length(),n=p.length();
        if(m==0&&n==1){
            return(0);
        }

        string s_cur,p_cur;
        bool dp[m+1][n+1];
        /// nth row ini
        for(int i=0;i<m;i++){
            dp[i][n] = 0;
        }
        dp[m][n] = 1;

        /// mth row
        dp[m][n-1] = 0;
        s_cur = s.substr(m);
        for(int i = n-2;i>=0;i--){
            p_cur = p.substr(i);
            if(p_cur[1]=='*'){
                dp[m][i] = dp[m][i+2];
            }else{
                dp[m][i] = 0;
            }
        }

        ///(n-1)th col
        p_cur = p.substr(n-1);
        for(int i=m-1;i>=0;i--){
            s_cur = s.substr(i);
            dp[i][n-1] = (s_cur[0]==p_cur[0]||p_cur[0]=='.')&&dp[i+1][n];

        }
        /// rest
        for(int j=n-2;j>=0;j--){
            for(int i= m-1;i>=0;i--){
                s_cur = s.substr(i);
                p_cur = p.substr(j);
                if(p_cur[1]=='*'){
                    dp[i][j] = dp[i][j+2] || ((s_cur[0]==p_cur[0]||p_cur[0]=='.')&&dp[i+1][j]);
                }else{
                    dp[i][j] = (s_cur[0]==p_cur[0]||p_cur[0]=='.') && dp[i+1][j+1];
                }
            }
        }
        return(dp[0][0]);
    }
};
