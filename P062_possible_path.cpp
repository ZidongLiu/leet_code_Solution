//
// Created by Zidong Liu on 8/22/18.
//
#include <algorithm>
#include <vector>

using namespace std;
///// beat 100%
///// combinatorials

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        return(NCR(m+n-2,min(m-1,n-1)));
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

///// dp solution, beat 100%

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n,0);
        vector<vector<int>> dp(m,row);
        for(int i=0;i<n;i++){
            dp[0][i] = 1;
        }
        for(int j=0;j<m;j++){
            dp[j][0] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return(dp[m-1][n-1]);
    }
};
