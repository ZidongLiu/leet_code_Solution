//
// Created by Zidong Liu on 8/23/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
//////// 100% beat, oms

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int status = 1, n =S.length(), this_len=0, this_rep=1, ind =0;
        vector<int> div, rep, len;
        vector<string> strr;
        string this_str;
        K=K-1;
        for(int i=0;i<n;i++){
            cout<<"i: "<<i<<endl;
            switch(status){
                case 1:
                    if(!(S[i]>='0'&&S[i]<='9')){
                        status = 2;
                        this_len++;
                        this_str.push_back(S[i]);
                    }

                    break;

                case 2:
                    if(S[i]<='9' && S[i]>='1'){
                        ind++;
                        status = 3;
                        div.push_back(this_len);
                        this_len*=(S[i]-'0');
                        this_rep*=(S[i]-'0');
                        strr.push_back(this_str);
                    }else{
                        this_len++;
                        this_str.push_back(S[i]);
                    }
                    break;

                case 3:
                    if(S[i]<='9' && S[i]>='1'){
                        this_len*=(S[i]-'0');
                        this_rep *= (S[i]-'0');
                    }else{
                        rep.push_back(this_rep);
                        len.push_back(this_len);
                        this_rep =1;
                        this_len++;
                        this_str.clear();
                        this_str.push_back(S[i]);
                        status = 2;
                    }
                    break;
            }

            if(this_len-1>=K){
                break;
            }

        }
        string ret;
        if(status==2){
            ret.push_back(this_str.back());
            return(ret);
        }else{
            rep.push_back(this_rep);
            len.push_back(this_len);
            /*
            cout<<ind<<endl;
            for(int i=0;i<ind;i++){
                cout<<setw(10)<<strr[i]<<setw(5)<<div[i]<<setw(5)<<rep[i]<<setw(5)<<len[i]<<endl;
            }
            */
            for(int i=ind-1;i>0;i--){
                K%=div[i];
                if(K>=len[i-1]){
                    ret.push_back(strr[i][K-len[i-1]]);
                    return(ret);
                }
            }
            K%=div[0];
            ret.push_back(strr[0][K]);
            return(ret);

        }
        /*
        switch(status){
            case 2:
                ind++;
                div.push_back(this_len);
                strr.push_back(this_str);
                len.push_back(this_len);
                rep.push_back(1);
                break;
            case 3:
                rep.push_back(this_rep);
                len.push_back(this_len);
                break;
        }
         */


    }
};