//
// Created by Zidong Liu on 8/15/18.
//

/// beat 14%
/// 28ms
#include <vector>
using namespace std;

vector<vector<char>> test_case = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','.','2','8'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> elem_index;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    elem_index.push_back({i,j});
                }
            }
        }

        int n = elem_index.size();

        vector<vector<char>> dp_possible_input;  /// the length is the same as the element we have filled
        vector<int> dp_index_of_current_input;  ///
        int the_index_of_fill=0;

        while(the_index_of_fill < n){
            vector<char> possible;
            vector<int> this_index = elem_index[the_index_of_fill];
            possible = find_possible_val(board, this_index);
            ///cout<<possible.size();

            if(possible.size()==0){
                /// Go back to find a possible dp place
                for(int back_index = the_index_of_fill-1; back_index >=0; ){
                    if(dp_index_of_current_input[back_index] < dp_possible_input[back_index].size()-1){
                        /// update dp vector
                        the_index_of_fill = back_index + 1;
                        dp_index_of_current_input[back_index]+=1;
                        dp_index_of_current_input.erase(dp_index_of_current_input.begin()+back_index+1,dp_index_of_current_input.end());
                        dp_possible_input.erase(dp_possible_input.begin()+back_index+1, dp_possible_input.end());

                        /// adjust board
                        board[elem_index[back_index][0]][elem_index[back_index][1]] = dp_possible_input[back_index][dp_index_of_current_input[back_index]];
                        break;
                    }else{
                        /// adjust board
                        board[elem_index[back_index][0]][elem_index[back_index][1]] = '.';
                        back_index--;
                    }

                }
            }else{

                /// update dp_vectors
                dp_possible_input.push_back(possible);
                dp_index_of_current_input.push_back(0);
                /// update board
                board[elem_index[the_index_of_fill][0]][elem_index[the_index_of_fill][1]] = possible[0];
                the_index_of_fill++;

            }

        }
    }

    vector<char> find_possible_val(vector<vector<char>> &board, vector<int> &index){
        vector<char>::const_iterator itr_row, itr_col, itr_block;
        vector<char> row_vec = board[index[0]],col_vec, block_vec;

        for(int j=0;j<9;j++){
            if(board[j][index[1]]!='.'){
                col_vec.push_back(board[j][index[1]]);
            }
        }
        int block_i = index[0]/3, block_j = index[1]/3;
        for(int i = block_i*3; i < block_i*3+3; i++){
            for(int j = block_j*3; j < block_j*3+3; j++){
                if(board[i][j]!='.'){
                    block_vec.push_back(board[i][j]);
                }
            }
        }

        vector<char> this_valid;

        for(char i='1';i<='9';i++){
            /// row_check
            itr_row = find(row_vec.cbegin(),row_vec.cend(),i);
            /// col_check
            itr_col = find(col_vec.cbegin(),col_vec.cend(),i);
            /// block_check
            itr_block = find(block_vec.cbegin(),block_vec.cend(),i);
            if(itr_row==row_vec.cend() && itr_col==col_vec.cend() && itr_block==block_vec.cend()){
                this_valid.push_back(i);
            }
        }

        return(this_valid);
    }
};

