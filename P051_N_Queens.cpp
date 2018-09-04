//
// Created by Zidong Liu on 8/20/18.
//
//////// refined dfs solution
//////// median solution, 4ms, beat 85%
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        vector<int> pos, rest_num;
        for(int i=0;i<n;i++){
            rest_num.push_back(i);
        }
        vector<vector<string>> ret_vec;
        dfs(n,pos,rest_num,ret_vec);
        return(ret_vec);
    }
    void dfs(int n, vector<int> pos, vector<int> rest_num, vector<vector<string>> &ret_vec){
        int row = pos.size();
        if(rest_num.size()==0){
            ret_vec.push_back(constructTable(n,pos));
        }else{
            for(int i=0;i<rest_num.size();i++){
                if(isValid(row,rest_num[i],pos)){
                    pos.push_back(rest_num[i]);
                    vector<int> new_rest_num = rest_num;
                    new_rest_num.erase(new_rest_num.begin()+i,new_rest_num.begin()+i+1);
                    dfs(n,pos,new_rest_num,ret_vec);
                    pos.pop_back();
                }
            }
        }
    }
    vector<string> constructTable(int n, vector<int> pos){
        vector<string> ret;
        for(auto elem:pos){
            string a(n,'.');
            a[elem] = 'Q';
            ret.push_back(a);
        }
        return(ret);
    }

    bool isValid(int row, int col, vector<int> pos){
        for(int i =0;i<pos.size();i++){
            if(abs(i-row)==abs(pos[i]-col)){
                return(0);
            }
        }
        return(1);
    }
};