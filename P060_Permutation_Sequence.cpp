//
// Created by Zidong Liu on 8/22/18.
//


///// 8ms, beat 25%
///// a little lower than medium

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> divisor,ret_num;
        divisor.push_back(1);
        ret_num.push_back(1);
        for(int i=2;i<=n;i++){
            ret_num.push_back(i);
            divisor.push_back(divisor.back()*(i-1));
        }

        string ret_str;
        add_next(divisor,ret_num,k-1,ret_str);
        return(ret_str);
    }

    void add_next(vector<int> divisor, vector<int> ret_num, int ret_k, string &ret_str){
        /*
        for(auto elem:divisor){
            cout<<setw(5)<<elem;
        }
        cout<<endl;
        for(auto elem:ret_num){
            cout<<setw(5)<<elem;
        }
        cout<<endl;
        cout<<"ret_k: "<< ret_k<<endl;
        cout<<"ret_Str: "<<ret_str<<endl;
        */
        if(ret_num.size()==1){
            ret_str.push_back(ret_num[0]+'0');
        }else{
            int d = ret_k/divisor.back();
            ret_str.push_back(ret_num[d]+'0');
            ret_k = ret_k-d*divisor.back();
            divisor.pop_back();
            ret_num.erase(ret_num.begin()+d,ret_num.begin()+d+1);
            add_next(divisor, ret_num, ret_k,ret_str);
        }
    }
};