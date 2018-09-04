//
// Created by Zidong Liu on 8/23/18.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<int> vec1, vec2;
        int n = grid.size();
        if(n==0){
            return(0);
        }
        int xy_sum =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xy_sum += (grid[i][j]>0);
            }
        }
        for(int i=0;i<n;i++){
            xy_sum+= *max_element(grid[i].begin(),grid[i].end());
        }

        for(int j=0;j<n;j++){
            int max_elem = grid[0][j];
            for(int i=1;i<n;i++){
                if(grid[i][j]>max_elem){
                    max_elem = grid[i][j];
                }
            }
            xy_sum+= max_elem;
        }
        return(xy_sum);
    }
};