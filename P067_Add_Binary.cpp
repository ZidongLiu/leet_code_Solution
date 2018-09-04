//
// Created by Zidong Liu on 8/24/18.
//
#include <vector>
#include <string>
using namespace std;
/////// good solution
////// medium, beat 100%
class Solution {
public:
    string addBinary(string a, string b) {

        string s1,s2;
        if(a.length()<b.length()){
            s1 = b;
            s2 = a;
        }else{
            s1 = a;
            s2 = b;
        }
        int m = s1.length(), carry=0, this_sum;
        for(int i=m-1;i>=0 && (s2.length()>0||carry>0);i--){
            ///cout<<"s1: "<<s1<<"   s2: "<<s2<<endl;
            if(s2.length()==0){
                this_sum = s1[i]-'0' + carry;
            }else{
                this_sum = (s1[i]-'0') + (s2.back()-'0') + carry;
                s2.pop_back();
            }
            s1[i] = this_sum%2 +'0';
            carry = this_sum/2;
        }

        if(carry==0){
            return(s1);
        }else{
            string s;
            s.push_back('1');
            s += s1;
            return(s);
        }
    }
};
