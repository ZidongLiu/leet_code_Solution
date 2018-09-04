//
// Created by Zidong Liu on 8/27/18.
//
#include <vector>
#include <string>
using namespace std;

/////// beat 50%
////// medium solution

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(n==0){
            return("");
        }
        vector<int> target(128,0);
        for(auto elem:t){
            target[(int) elem]++;
        }

        sort(t.begin(),t.end());
        t.erase(unique(t.begin(),t.end()),t.end());
        /*
        for(auto elem:t){
            cout<<"elem: "<<elem<<" target: "<<target[(int) elem]<<endl;
        }
         */
        int tlen = t.length();
        ///cout<<"tlen: "<<tlen<<endl;
        int reach=0;
        int left=0, right=0;
        int mode =1;
        int len=0;
        while(target[(int) s[left]]==0){
            left++;
            right++;
        }
        int maybe_left;
        vector<int> have(128,0);
        while(target[(int) s[left]]==0){
            left++;
            right++;
        }
        for(int i=left;i<n;i++){
            if(mode){

                have[(int) s[i]]++;
                if(have[(int) s[i]]==target[(int) s[i]]){
                    reach++;
                }
                ///cout<<"i: "<<i<<"   reach:  "<<reach<<endl;
                if(reach==tlen){
                    ///cout<<"here"<<endl;
                    right = i;
                    while(have[(int) s[left]] > target[(int) s[left]]){
                        have[(int) s[left]]--;
                        left++;
                    }
                    len = (right-left+1);
                    maybe_left = left;
                    mode =0;
                    //cout<<"left: "<<left<<"   maybe_left:   "<<maybe_left<<"    right:"<<right<<endl;
                }

            }else{
                have[(int) s[i]]++;
                //cout<<"S[i]: "<<s[i]<<"  num: "<<have[(int) s[i]]<<endl;
                //cout<<"S[maybe_left]: "<<s[maybe_left]<<"   num:  "<<have[(int) s[maybe_left]]<<"   target[smaybe]: "<<target[(int) s[maybe_left]]<<endl;
                if(have[(int) s[maybe_left]] > target[(int) s[maybe_left]]){
                    do{
                        have[(int) s[maybe_left]]--;
                        maybe_left++;
                    }while(have[(int) s[maybe_left]]>target[(int) s[maybe_left]]);
                    //cout<<"left: "<<left<<"   maybe_left:   "<<maybe_left<<"    right:"<<right<<endl;
                    if(i-maybe_left+1<len){
                        right = i;
                        left = maybe_left;
                        len = (right-left+1);
                    }
                }
            }
        }
        ///cout<<"left: "<<left<<"   maybe_left:   "<<maybe_left<<"    right:"<<right<<endl;
        return(mode?"":s.substr(left,len));
    }
};