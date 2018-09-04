//
// Created by Zidong Liu on 8/24/18.
//
#include <algorithm>
#include <cmath>
using namespace std;
/////// take care of integer overflow
/////// median solution, 4ms, beat 97%

class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return(x);
        }else{
            int out_of_range = pow(2,34);
            int left = 1, right = pow(2,15), mid;
            while(left<=right){
                mid = (left+right)/2;
                if((mid*mid)>x){
                    right = mid;
                }else if((mid+1)*(mid+1)<=x){
                    left = mid+1;
                }else{
                    return(mid);
                }
            }

            //cout<<"here"<<endl;
            left = pow(2,15)+1;
            right = 3 * pow(2,14);

            for(int i=0;i<100;i++){
                //cout<<"mid: "<<mid<<endl;
                mid = (left+right)/2;
                if(mid*mid<0 || mid*mid > x){
                    right =mid;
                }else if((mid+1)*(mid+1)<=x && (mid+1)*(mid+1)>0){
                    left = mid+1;
                }else{
                    return(mid);
                }
            }
        }
    }
};