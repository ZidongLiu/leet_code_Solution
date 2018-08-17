//
// Created by Zidong Liu on 5/28/18.
//

#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sgn = 0,lead = 0,mode = 0;
        string ret_str;
        for(auto elem:str){
            if(mode ==0){
                if(elem==' '){
                    continue;
                }else if(elem<='9'&&elem>='0'){
                    mode = 1;
                    sgn = 1;
                    if(elem!='0'){
                        lead = 1;
                        ret_str.push_back(elem);
                    }
                    continue;
                }else if(elem=='-'||elem=='+'){
                    mode = 1;
                    if(elem=='-'){
                        sgn = -1;
                    }else{
                        sgn = 1;
                    }
                    continue;
                }else{
                    return(0);
                }
            }else if(mode==1){
                if(elem<='9'&&elem>='0'){
                    if(lead==0){
                        if(elem!='0'){
                            lead = 1;
                            ret_str.push_back(elem);
                        }
                        continue;
                    }else{
                        ret_str.push_back(elem);
                        if(ret_str.length()>10){///length exceed
                            if(sgn==1){
                                return(pow(2,31)-1);
                            }else{
                                return(-pow(2,31));
                            }
                        }
                    }
                }else{
                    break;
                }
            }else{
                cout<<"unknow case"<<endl;
            }
        }

        if(lead==0){
            return(0);
        }

        long ret_v;
        ret_v = stol(ret_str);
        if(sgn>0){
            if(ret_v > pow(2,31)-1){
                return(pow(2,31)-1);
            }else{
                return(ret_v);
            }
        }else{
            if(ret_v>pow(2,31)){
                return(-pow(2,31));
            }else{
                return(-ret_v);
            }
        }
    }
};

