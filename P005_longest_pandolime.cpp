//
// Created by Zidong Liu on 5/25/18.
//

#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0||s.length()==1){
            return s;
        }else{
            int max_len=0,this_len;
            string::iterator left,right,left_temp,right_temp,ret_left,ret_right;
            string ret_str;
            left = s.begin();
            right = s.begin();
            while(left!=s.end()){
                if(*(right+1)==*left){///extend the right to the rightmost place
                    ++right;
                }else{/// check the longest panlindrome
                    left_temp = left;
                    right_temp = right;
                    while(left_temp!=s.begin()&&right_temp!=(s.end()-1)&& *(left_temp-1)==*(right_temp+1)){
                        left_temp--;
                        right_temp++;
                    }
                    this_len = distance(left_temp,right_temp)+1;
                    if(this_len>max_len){
                        max_len = this_len;
                        ret_left = left_temp;
                        ret_right = right_temp;
                    }
                    left = right+1;
                    right++;

                }
            }
            copy(ret_left,ret_right+1,back_inserter(ret_str));
            return ret_str;
        }
    }
};

