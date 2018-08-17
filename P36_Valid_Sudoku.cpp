//
// Created by Zidong Liu on 8/15/18.
//



///// this is average solution, median
///// beat 97%, 12ms

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /// row check;
        for(int i=0;i<9;i++){
            vector<char> this_vec = board[i], this_vec_clear;
            for(auto elem:this_vec){
                if(elem!='.'){
                    this_vec_clear.push_back(elem);
                }
            }
            if(!is_vec_OK(this_vec_clear)){
                return(0);
            }
        }

        /// col check
        vector<vector<int>> this_index(9);
        for(int j=0; j<9;j++){
            for(int i=0;i<9;i++){
                this_index[i] = {i,j};
            }
            vector<char> this_vec = getSubstr(board,this_index);
            if(!is_vec_OK(this_vec)){
                return(0);
            }
        }

        /// block check
        for(int k=0;k<9;k++){
            int i,j, ind = 0;
            i = k/3;
            j = k-i*3;
            for(int i_sub = i*3;i_sub<i*3+3;i_sub++){
                for(int j_sub=j*3; j_sub<j*3+3;j_sub++){
                    this_index[ind++] = {i_sub,j_sub};
                }
            }
            vector<char> this_vec = getSubstr(board,this_index);
            if(!is_vec_OK(this_vec)){
                return(0);
            }
        }
        return(1);
    }

    vector<char> getSubstr(vector<vector<char>> &board, vector<vector<int>> &index){
        vector<char> ret_vec;
        for(auto elem: index){
            if(board[elem[0]][elem[1]]!='.'){
                ret_vec.push_back(board[elem[0]][elem[1]]);
            }
        }
        return(ret_vec);
    }

    bool is_vec_OK(vector<char> &input_vec){
        int n=input_vec.size();
        for(int i=0;i<n-1;i++){
            vector<char>::iterator itr = find(input_vec.begin()+i+1,input_vec.end(),input_vec[i]);
            if(itr!=input_vec.end()){
                return(0);
            }
        }
        return(1);
    }
};