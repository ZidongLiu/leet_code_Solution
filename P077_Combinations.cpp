//
// Created by Zidong Liu on 8/27/18.
//
#include <vector>
using namespace std;
///////// Solution 288 ms, too slow

class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> num;
        vector<vector<int>> ret_vec;
        for(int i=1;i<=n;i++){
            num.push_back(i);
        }
        vector<int> this_vec;
        int i =0;
        fly(this_vec,num,i,k,n,ret_vec);
        return(ret_vec);
    }
    void fly(vector<int> this_vec, vector<int> &num, int i, int k, int &n, vector<vector<int>> &retvec){
        if(k==0){
            retvec.push_back(this_vec);
        }else{
            for(int j=i;j<n;j++){
                vector<int> new_vec = this_vec;
                new_vec.push_back(num[j]);
                fly(new_vec,num,j+1,k-1,n,retvec);
            }
        }
    }
};


///// decrease from 288 to 212ms
//// beat 2.83%

class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> retvec;
        vector<int> this_vec;
        optimized_fly(this_vec, 1, k, n, retvec);

    }

    void optimized_fly(vector<int> this_vec, int i, int k, int &n, vector<vector<int>> &retvec){
        if(k==1){
            for(;i<=n;i++){
                this_vec.push_back(i);
                retvec.push_back(this_vec);
                this_vec.pop_back();
            }
        }else{
            for(;i<=n;i++){
                this_vec.push_back(i);
                optimized_fly(this_vec, i+1,k-1,n,retvec);
                this_vec.pop_back();
            }
        }
    }
};


//////// good solution
