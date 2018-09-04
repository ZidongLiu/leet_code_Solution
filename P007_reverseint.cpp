//
// Created by Zidong Liu on 5/27/18.
//


#include <string>
#include<cmath>

using namespace std;

// reverse string
class Solution {
public:
    int reverse(int x) {
        if(x < -pow(2,31)||x >(pow(2,31)-1)){
            return(0);
        }else{
            int sgn,abs_v;
            abs_v = abs(x);
            string sv = to_string(abs_v);
            if(x<0){
                sv.push_back('-');
            }
            string ret_str(sv.rbegin(),sv.rend());
            long ret_v = stol(ret_str);
            if(ret_v < -pow(2,31)||ret_v >(pow(2,31)-1)){
                return(0);
            }else{
                return(int(ret_v));
            }

        }
    }
};


// int division

class Solution2 {
public:
    int reverse(int x) {
        if(x<-pow(2,31)||x>pow(2,32)){
            return(0);
        }
        long ret_v=0;
        if(x>0){
            int abs_x = abs(x);
            while(abs_x>0){
                ret_v = ret_v*10 + abs_x%10;
                abs_x /=10;
            }
            if(ret_v>(pow(2,31)-1)){
                return(0);
            }else{
                return(ret_v);
            }
        }else{
            int abs_x = abs(x);
            while(abs_x>0){
                ret_v = ret_v*10 + abs_x%10;
                abs_x /=10;
            }
            if(ret_v>pow(2,31)){
                return(0);
            }else{
                return(-ret_v);
            }
        }
    }
};
