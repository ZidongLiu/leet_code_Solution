//
// Created by Zidong Liu on 8/17/18.
//

#include <vector>
#include <cmath>
using namespace std;
///////// tooo complicated, 8ms, beat 10%
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return(1);
        }else{
            if(x==0){
                return(0);
            }else if(x==1){
                return(1);
            }else if(x==-1){
                return(n%2==0?1:-1);
            }else{
                int sign, my_n, my_x;
                if(x<0){
                    sign = n%2==0?1:-1;
                    my_x = -x;
                }else{
                    sign =1;
                    my_x = x;
                }
                if(n<0){
                    my_n = -n;
                    my_x = 1/x;
                }else{
                    my_n = n;
                    my_x = x;
                }
                ///////////////////// exception done
                vector<double> intermediate;
                intermediate.push_back(1);
                intermediate.push_back(my_x);
                int this_pow = 1;
                while(this_pow <= my_n){
                    intermediate.push_back(intermediate.back()*intermediate.back());
                    this_pow*=2;
                }
                double ret_val=1;
                while(intermediate.size()>1){
                    while(my_n >= this_pow){
                        ret_val*=intermediate.back();
                        my_n -= this_pow;
                    }
                    this_pow/=2;
                }
                return(sign*ret_val);
            }
        }
    }
};

////// average, 4ms, median
////// beat 98%

class Solution1 {
public:
    double myPow(double x, int n) {
        if(n==-pow(2,31)){
            if(abs(x)>1){
                return(0);
            }
        }
        if(n<0){
            return(1/pow(x,-n));
        }else{
            return(pow(x,n));
        }
    }
    double pow(double x, int n){
        if(n==0){
            return(1);
        }else{
            double v = pow(x,n/2);
            if(n%2==0){
                return(v*v);
            }else{
                return(v*v*x);
            }
        }
    }
};