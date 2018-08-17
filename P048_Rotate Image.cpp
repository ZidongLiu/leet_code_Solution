//
// Created by Zidong Liu on 8/17/18.
//
#include <vector>
#include <algorithm>
using namespace std;
/////// This solution is from mathematics, 4ms
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layer = n/2;
        vector<int> ind(2);
        for(int i=0; i < layer;i++){
            ind[0] = i;
            for(int j=i;j<=(n-2-i);j++){
                ind[1] = j;
                rotate_for_ind(matrix,ind);
            }
        }
    }
    void rotate_for_ind(vector<vector<int>> &matrix, vector<int> ind){
        int temp1,temp2;
        vector<int> next_ind(2);
        next_ind[0] = ind[1];
        next_ind[1] = matrix.size()-1-ind[0];
        temp1 = matrix[next_ind[0]][next_ind[1]];
        matrix[next_ind[0]][next_ind[1]] = matrix[ind[0]][ind[1]];
        ind = next_ind;
        for(int i=2; i<=4;i++){
            next_ind[0] = ind[1];
            next_ind[1] = matrix.size()-1-ind[0];
            temp2 = matrix[next_ind[0]][next_ind[1]];
            matrix[next_ind[0]][next_ind[1]] = temp1;
            temp1 = temp2;
            ind = next_ind;
        }
    }
};

vector<vector<int>> mat ={
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
};


vector<vector<int>> mat2 ={
        { 1,2,3},
        { 4,5,6},
        { 7,8,9}
};

//////// faster method using rotate attributes, 0ms
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};