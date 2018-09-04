//
// Created by Zidong Liu on 8/24/18.
//
#include <vector>
using namespace std;
///////// dp, medium solution

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return(n);
        }else{
            vector<int> dp(n,0);
            dp[0] = 1;
            dp[1] = 2;
            for(int i=2;i<n;i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return(dp[n-1]);
        }
    }
};


class Solution1 {
public:
    int climbStairs(int n) {
        if(n<=2){
            return(n);
        }else{
            vector<int> dp(n,0);
            dp[0] = 1;
            dp[1] = 2;
            for(int i=2;i<n;i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return(dp[n-1]);
        }
    }
    int comb(int n){
        int p,q;
        int ret=0;
        for(p=0;p<=n/2;p++){
            q = n-2*p;
            ret += NCR(p+q,p);
        }
        return(ret);
    }

    int NCR(int n, int r)
    {
        if (r == 0) return 1;

        if (r > n / 2) return NCR(n, n - r); // save some computation

        long res = 1;

        for (int k = 1; k <= r; ++k)
        {
            res *= n - k + 1;
            res /= k;
        }

        return res;
    }
};