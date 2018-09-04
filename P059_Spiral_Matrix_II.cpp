//
// Created by Zidong Liu on 8/22/18.
//

///// lower than medium
///// 4ms, beat 30%

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n);
        vector<vector<int>> ret_mat(n,row);
        int level = n/2;
        int k=1;
        for(int i=0;i<level;i++){
            for(int j =i;j<=n-2-i;j++){
                ret_mat[i][j] = k;
                k++;
            }
            for(int j=i;j<=n-2-i;j++){
                ret_mat[j][n-1-i] = k;
                k++;
            }
            for(int j = n-1-i;j>=i+1;j--){
                ret_mat[n-1-i][j] = k;
                k++;
            }
            for(int j= n-1-i;j>=i+1;j--){
                ret_mat[j][i] = k;
                k++;
            }
        }
        if(n%2==1){
            ret_mat[level][level] = k;
        }
        return(ret_mat);
    }
};