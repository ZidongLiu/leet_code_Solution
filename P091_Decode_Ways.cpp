//
// Created by Zidong Liu on 9/1/18.
//

#include <string>
#include <vector>

using namespace std;
///////// TLE solution, idea is good
////////
class Solution1 {
public:
    int numDecodings(string s) {
        int ret=0, n=s.length();
        if(n==0){
            return(0);
        }else{
            helper(0,n,s,ret);
            return(ret);
        }
    }

    void helper(int ind, int &n, string &s, int &ret){
        if(ind==n){
            ret++;
        }else if(ind>n){
            return;
        }else{
            if(s[ind]=='0'){
                return;
            }else{
                helper(ind+1,n,s,ret);
                if(n-ind >=2 && isvald2(s.substr(ind,2))){
                    helper(ind+2,n,s,ret);
                }
            }
        }
    }

    bool isvald2(string str){
        int n = str.length();
        if(str[0]=='0'||str[0]>'2'){
            return(0);
        }else if(str[0]=='2'){
            return(str[1]<='6');
        }else{
            return(1);
        }
    }
};

//////////////// DP solution
/////////////// beat 100%

class Solution {

public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0){
            return(0);
        }else if(n==1){
            return(s[0]!='0');
        }
        vector<int> dp(n,0);
        //// initialization
        dp[n-1] = (s[n-1]!='0');

        if(s[n-2]=='0'){
            dp[n-2] =0;
        }else if(isvald2(s.substr(n-2,2))){
            dp[n-2] = 1 + dp[n-1];
        }else{
            dp[n-2] = dp[n-1];
        }
        ///// loop
        for(int i=n-3;i>=0;){
            if(s[i]=='0'){
                if(i==0 || s[i-1]=='0'||s[i-1]>'2'){
                    return(0);
                }else{
                    dp[i] = 0;
                    dp[i-1] = dp[i+1];
                    i-=2;
                }
            }else{
                dp[i] = dp[i+1];
                if(isvald2(s.substr(i,2))){
                    dp[i] += dp[i+2];
                }
                i--;
            }
        }
        /*
        for(auto elem:dp){
            cout<<setw(4)<<elem;
        }
        cout<<endl;
         */
        return(dp[0]);
    }

    bool isvald2(string str){
        int n = str.length();
        if(str[0]=='0'||str[0]>'2'){
            return(0);
        }else if(str[0]=='2'){
            return(str[1]<='6');
        }else{
            return(1);
        }
    }
};