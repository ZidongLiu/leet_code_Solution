//
// Created by Zidong Liu on 8/17/18.
//



#include <string>
#include <iostream>

using namespace std;
//// recursively solving the problem
////// time limit exceed for large problem
class Solution1 {
public:
    bool isMatch(string s, string p) {
        string my_p;
        int n_s = s.length(), n_p = p.length();
        for(auto elem: p){
            if(elem!='*' || my_p.back()!='*'){
                my_p.push_back(elem);
            }
            bool retbool=0;
            match(0,0,0,n_s,n_p,s,p,retbool);
            return(retbool);
        }
    }
    void match(bool preceding, int s_i, int p_i, int n_s, int n_p, string &s, string &p, bool &retbool){
        if(s_i>=n_s && p_i>=n_p){
            retbool = 1;
        }else{
            if(preceding){
                if(s_i<n_s){
                    match(1,s_i+1,p_i,n_s,n_p,s,p,retbool);
                    if(p_i<n_p &&(s[s_i] == p[p_i] || p[p_i] == '?')){
                        match(0,s_i+1,p_i+1,n_s,n_p,s,p,retbool);
                    }
                }
            }else{
                if(p[p_i]=='*'){
                    match(0,s_i,p_i+1,n_s,n_p,s,p,retbool);
                    match(1,s_i+1,p_i+1,n_s,n_p,s,p,retbool);
                }else{
                    if(s[s_i] == p[p_i] || p[p_i] == '?'){
                        match(0,s_i+1,p_i+1,n_s,n_p,s,p,retbool);
                    }
                }
            }
        }
    }
};


////////// DP great solution
////32ms, beat 69.91%

class Solution {
public:
    bool isMatch(string s, string p) {
        bool match[s.length()+1][p.length()+1];
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=p.length();j++){
                match[i][j]=0;
            }
        }

        match[0][0] =1;
        for(int i = 1;i<=p.length();i++){
            if(p[i-1]=='*'){
                match[0][i] = 1;
            }else{
                break;
            }
        }


        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    ///cout<<" flag1: fit "<<match[i-1][j-1]<<endl;
                    match[i][j] = match[i-1][j-1];
                }else if(p[j-1]=='*'){
                    ///cout<<" flag2"<<endl;
                    match[i][j] = match[i-1][j] || match[i][j-1];
                }
                ///cout<<"i: "<<i<<"  j: "<<j<<"    match: "<<match[i][j]<<endl;
            }
        }

        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=p.length();j++){
                cout<<match[i][j]<<"   ";
            }
            cout<<endl;
        }

        return(match[s.length()][p.length()]);
    }
};