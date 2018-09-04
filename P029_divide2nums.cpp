//
// Created by Zidong Liu on 6/4/18.
//
#include<vector>
#include <cmath>

using namespace std;
// 33ms, beat30%
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0){
            return(0);
        }else
        if(divisor == 1){// dividend !=0
            return(dividend);
        }else if(divisor==-1){// dividend!=0, divosr
            if(dividend==-pow(2,31)){
                return(pow(2,31)-1);
            }else{
                return(-dividend);
            }
        }else if(divisor==-pow(2,31)){
            if(dividend == -pow(2,31)){
                return(1);
            }else{
                return(0);
            }
        }
        int sgn,carry=0;
        if((dividend<0&&divisor<0)||(dividend>0&&divisor>0)){
            sgn=1;
        }else{
            sgn=-1;
        }
        if(dividend==-pow(2,31)){
            dividend +=abs(divisor);
            carry=1;
        }
        vector<long> div,num;

        dividend = abs(dividend);
        divisor = abs(divisor);

        long sum=divisor;
        div.push_back(divisor);
        num.push_back(1);
        while(sum<dividend){/// reach the upper bound
            div.push_back(div.back()*2);
            sum += div.back();
            num.push_back(1);
            //cout<<sum<<endl;
        }

        if(sum==dividend){
            int sz = div.size();
            if(sgn<0){
                return(-(pow(2,sz)-1+carry));
            }else{
                return(pow(2,sz)-1+carry);
            }
        }
        sum -=div.back();
        div.pop_back();
        num.pop_back();
        long temp_sum;
        int idx = div.size();
        while(idx>=0){
            temp_sum = sum+div[idx];
            if(temp_sum<dividend){
                sum=temp_sum;
                ++num[idx];
            }else if(temp_sum==dividend){
                ++num[idx];
                break;
            }
            --idx;
        }

        long k=carry;
        for(int i=0;i<num.size();++i){
            k+= num[i]*pow(2,i);
        }
        if(sgn<0){
            if(k<=pow(2,31)){
                return(-k);
            }else{
                return(pow(2,31));
            }
        }else{
            if(k<=pow(2,31)-1){
                return(k);
            }else{
                return(pow(2,31));
            }

        }
    }
};