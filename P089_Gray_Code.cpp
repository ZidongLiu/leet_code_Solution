//
// Created by Zidong Liu on 9/1/18.
//
#include <vector>
#include <cmath>
using namespace std;
////////// 8ms, beat 4.73%
////////// idea is OK

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0){
            vector<int> a={0};
            return(a);
        }else{
            vector<int> b((int) pow(2,n), 0);
            b[0] = 0;
            b[1] = 1;
            for(int i=2;i<=n;i++){
                int this_len = pow(2,n-1);
                reverse_copy(b.begin(),b.begin()+this_len,b.begin()+this_len);
                for(int j = this_len;j<pow(2,n);j++){
                    b[j] += pow(2,i-1);
                }
            }
            return(b);
        }
    }
};