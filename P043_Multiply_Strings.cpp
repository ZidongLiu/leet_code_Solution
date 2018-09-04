//
// Created by Zidong Liu on 8/16/18.
//



/// 240ms,
/// beat 0%
/// could improve the design by involve more digits


#include <string>
using namespace std;

class Solution1 {///// intuitively thinking, bit by bit
public:

    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return("0");
        }
        int n1 = num1.length(), n2 = num2.length();
        string ret_str="0";
        //cout<<ret_str<<endl;
        for(int i = n1-1; i >= 0; i--){
            int this_num1 = num1[i]-'0';

            for(int j = n2-1; j>=0 ;j--){
                int this_num2 = num2[j] - '0', prod, carry;
                string this_add((n1+n2-2-i-j),'0');
                prod = this_num2*this_num1;
                if(prod>=10){
                    carry = prod/10;
                    ///cout<<carry<<endl;
                    ///cout<<(prod-carry*10)<<endl;
                    this_add += (prod-carry*10) + '0';
                    this_add += carry + '0';
                }else{
                    this_add += prod +'0';
                }
                ///cout<<"this_add: "<<this_add<<endl;
                ret_str = str_add_int_2_str(ret_str,this_add);
                ///cout<<ret_str<<endl;

            }
        }
        reverse(ret_str.begin(),ret_str.end());
        return(ret_str);
    }

    string str_add_int_2_str(string &num1, string &num2){ /// num are stored in reverse order
        string ret_str,num_a, num_b;
        int n1 = num1.length(), n2 = num2.length(),  n_a, n_b, carry=0, sum, dig_a, dig_b;
        int stop_ind;

        if(n1<n2){
            num_a = num1;
            num_b = num2;
            n_a = n1;
            n_b = n2;
        }else{
            num_a = num2;
            num_b = num1;
            n_a = n2;
            n_b = n1;
        }
        stop_ind = n_a;
        for(int i=0;i<n_a;i++){
            dig_a =  num_a[i] - '0';
            dig_b = num_b[i] - '0';
            sum = dig_a + dig_b + carry;
            carry = sum/10;
            ret_str += '0' + (sum-carry*10);
        }
        while(carry!=0  && stop_ind<= n_b-1){
            sum = carry + num_b[stop_ind] -'0';
            carry = sum/10;
            ret_str += '0' + (sum-carry*10);
            stop_ind++;
        }
        if(carry!=0){
            ret_str +='1';
            return(ret_str);
        }else{
            ret_str += num_b.substr(stop_ind,n_b);
        }
        return(ret_str);
    }
};


