//
// Created by Zidong Liu on 6/1/18.
//
#include <vector>
#include <string>
#include <map>

using namespace std;
/// 3 ms solution, beat 91.13%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret_vec;
        if(ret_vec.size()==0){
            return(ret_vec);
        }
        vector<string> mapping=buildMap();
        vector<int> round_sys;
        int total_num=1,this_digit;
        vector<int> digit;
        for(auto elem: digits){
            this_digit = elem-'0';
            digit.push_back(this_digit);
            round_sys.push_back(mapping[this_digit].length());
            total_num*=mapping[this_digit].length();
        }
        vector<int> this_coord(0,digits.length());
        for(int i=0;i<total_num-1;i++){
            string this_str;
            for(int j=0;j<digits.length();j++){
                this_str.push_back(mapping[digit[j]].at(this_coord[j]));
            }
            ret_vec.push_back(this_str);
            this_coord = next_coord(this_coord,round_sys);
        }
        string this_str;
        for(int j=0;j<digits.length();j++){
            this_str.push_back(mapping[digit[j]].at(this_coord[j]));
        }
        ret_vec.push_back(this_str);
        return(ret_vec);
    }

private:
    vector<string> buildMap(){
        vector<string> map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    }

    vector<int> next_coord(vector<int> this_coord, vector<int> round_sys){
        ++this_coord[this_coord.size()-1];
        for(int i=this_coord.size()-1;i>=0;--i){
            if(this_coord[i]==round_sys[i]-1){
                this_coord[i] = 0;
                ++this_coord[i-1] ;
            }else{
                return(this_coord);
            }
        }
        return(this_coord);
    }
};