//
// Created by Zidong Liu on 8/30/18.
//
#include <vector>
using namespace std;
/////// tle
class Solution1 {
public:
    int max_area;
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        if(m==0){
            return(0);
        }
        int n=matrix[0].size();
        if(n==0){
            return(0);
        }
        max_area =0;
        dfs({0,m-1},{0,n-1},{0,0},matrix);
        return(max_area);
    }

    void dfs(vector<int> row_range, vector<int> col_range, vector<int> cur_index, vector<vector<char>> &matrix){
        if(row_range[0]>row_range[1] || col_range[0]>col_range[1]){
            return;
        }
        int i=cur_index[0],j;
        for(;i<=row_range[1];i++){
            for(j=col_range[0];j<=col_range[1];j++){
                if(matrix[i][j]=='0'){
                    if(i > row_range[0]) { //// no upper area
                        int this_val = (i - row_range[0] + 1) * (col_range[1] - col_range[0] + 1);
                        max_area = max(max_area, this_val);
                    }
                    dfs({row_range},{col_range[0],j-1},{i+1,col_range[0]},matrix); //// left sub matrix
                    dfs({row_range},{j+1,col_range[1]},{i,j+1},matrix); //// right sub matrix
                    dfs({i+1,row_range[1]}, col_range, {i+1,col_range[0]},matrix); //// bot sub mat
                    return;
                }
            }
        }
        int this_val = (row_range[1]-row_range[0])*(col_range[1]-col_range[0]);
        max_area = max(max_area,this_val);
        return;
    }
};




/////////////// use maximal rectangle in histogram
/////////////// great solution, beat 50%

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0){
            return(0);
        }
        int n = matrix[0].size();
        if(n==0){
            return(0);
        }
        vector<int> cur_hist(n,0);
        int max_area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    cur_hist[j]++;
                }else{
                    cur_hist[j]=0;
                }
            }
            max_area = max(max_area,largestRectangleArea(cur_hist));
        }
        return(max_area);
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return(0);
        }else{
            vector<int> cur_height, cur_index;
            int max_area = 0;

            for(int i=0;i<n;i++){
                ///cout<<"i"<<i<<endl;
                if(cur_height.empty() || cur_height.back() < heights[i]){
                    cur_height.push_back(heights[i]);
                    cur_index.push_back(i);
                }else{
                    int cur_n = cur_height.size(), temp;
                    for(int j=cur_n-1;j>=0;j--){
                        if(cur_height[j]>=heights[i]){
                            max_area = max(max_area,cur_height.back()*(i-cur_index.back()));
                            temp = cur_index[j];
                            cur_height.pop_back();
                            cur_index.pop_back();
                        }else{
                            break;
                        }
                    }
                    cur_height.push_back(heights[i]);
                    cur_index.push_back(temp);
                }
                /*
                for(auto elem:cur_height){
                    cout<<elem<<"  ";
                }
                cout<<endl;
                for(auto elem:cur_index){
                    cout<<elem<<"  ";
                }
                cout<<endl;
                 */
            }

            while(!cur_height.empty()){
                max_area = max(max_area, cur_height.back()*(n-cur_index.back()));
                cur_height.pop_back();
                cur_index.pop_back();
            }
            return(max_area);
        }
    }
};

vector<vector<char>> my_mat={
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
};