//
// Created by Zidong Liu on 8/27/18.
//
#include <vector>
#include <string>
using namespace std;
/////// good solution
/////// beat 80%

class Solution {
public:
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        bool ret=0;
        int m = board.size();
        if(m==0){
            return(0);
        }
        int n=board[0].size();
        if(n==0){
            return(0);
        }
        int nw = word.size();
        vector<bool> vis_row(n,0);
        vector<vector<bool>> this_visited(m,vis_row);
        visited = this_visited;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && dfs(i,j,0,word,board)){
                    return(1);
                }
            }
        }


        return(ret);
    }

    bool dfs(int row, int col, int k, string &word, vector<vector<char>> &board){
        if(k>=word.length()){
            return(1);
        }else{
            if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || visited[row][col] || word[k]!=board[row][col]){
                return(0);
            }else{
                visited[row][col] = 1;
                if(dfs(row-1,col,k+1,word,board)||dfs(row,col-1,k+1,word,board)||dfs(row+1,col,k+1,word,board)||dfs(row,col+1,k+1,word,board)){
                    return(1);
                }else{
                    visited[row][col] =0;
                    return(0);
                }
            }
        }
    }
};

vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
};