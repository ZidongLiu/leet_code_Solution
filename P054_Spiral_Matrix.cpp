//
// Created by Zidong Liu on 8/21/18.
//
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        int m = matrix.size(), n = matrix[0].size();
        int level = (min(m,n)+1)/2;
        vector<int> ret_vec;
        for(int i=0;i<level;i++){
            for(int j=i; j<n-1-i;j++){
                ret_vec.push_back(matrix[i][j]);
            }
            for(int row = i; row < m - 1-i;row++){
                ret_vec.push_back(matrix[row][n-1-i]);
            }
            for(int col = n-1-i;col>=i+1;col--){
                ret_vec.push_back(matrix[m-1-i][col]);
            }
            for(int row = m-1-i; row>=i+1;row--){
                ret_vec.push_back(matrix[row][i]);
            }
        }
        return(ret_vec);
    }
};

vector<vector<int>> test1 ={
                        {1,2,3},
                        {4,5,6},
                        {7,8,9}
};