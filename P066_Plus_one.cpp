//
// Created by Zidong Liu on 8/24/18.
//
#include <vector>
using namespace std;
///// 4ms, beat 0%

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        if(digits[0]==0){
            ret.push_back(1);
            return(ret);
        }else{
            int carry=1, this_sum;
            for(int i=digits.size()-1;i>=0;i--){
                this_sum = digits[i]+carry;
                carry = this_sum/10;
                digits[i] = this_sum%10;
                if(carry==0){
                    break;
                }
            }

            if(carry==1){
                ret.push_back(1);
                for(auto elem:digits){
                    ret.push_back(elem);
                }
                return(ret);
            }else{
                return(digits);
            }
        }
    }
};