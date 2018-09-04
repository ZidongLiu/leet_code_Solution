//
// Created by Zidong Liu on 6/3/18.
//
#include <string>
#include <map>
using namespace std;

//4ms, beat 95%
class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0){
            return(1);
        }
        if(s.length()%2==1){
            return(0);
        }
        map<char,char> mapping{
                {'(',')'},
                {'[',']'},
                {'{','}'}
        };
        string expect;
        for(auto elem:s){
            if(expect.length()==0){
                expect += mapping[elem];
                continue;
            }
            if(elem=='('||elem=='['||elem=='{'){
                expect.push_back(mapping[elem]);
            }else{
                if(elem==*(expect.end()-1)){
                    expect.pop_back();
                    continue;
                }else{
                    return(0);
                }
            }
        }
        return(expect.length()==0);
    }

};