//
// Created by Zidong Liu on 8/26/18.
//
#include <vector>
#include <algorithm>
////// great solution
///// beat 94%
///// 8ms

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0){
            return(0);
        }
        int n = matrix[0].size();
        if(n==0){
            return(0);
        }
        if(m==1){
            return(binary_search(matrix[0].begin(),matrix[0].end(),target));
        }
        if(m==2){
            return(binary_search(matrix[0].begin(),matrix[0].end(),target) || binary_search(matrix[1].begin(),matrix[1].end(),target));
        }
        int left = 0, right = m-1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(mid==0){
                break;
            }
            if(target<=matrix[mid-1][n-1]){
                right = mid;
            }else if(target>matrix[mid][n-1]){
                left = mid+1;
            }else{
                return(binary_search(matrix[mid].begin(),matrix[mid].end(),target));
            }
        }
        if(mid==0){
            return(binary_search(matrix[0].begin(),matrix[0].end(),target));
        }
        return(0);
    }
};

vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
