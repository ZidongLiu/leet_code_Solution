//
// Created by Zidong Liu on 5/29/18.
//

#include<vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> div={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roam={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ret_str={""};
        int mult;
        for(int i=0;i<div.size();i++){
            mult = num/div[i];
            for(int j=1;j<=mult;j++){
                ret_str += roam[i];
            }
            num %=div[i];
            if(num==0){
                break;
            }
        }
        return(ret_str);
    }
};

