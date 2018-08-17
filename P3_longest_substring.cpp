

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    static int  lengthOfLongestSubstring(string s) {
        if(s.length()==1||s.length()==0){
            return s.length();
        }else{
            int max = 0;
            int this_len;
            string::iterator sub_start=s.begin(),sub_end;
            sub_end = sub_start+1;
            for(int end_ind =1;end_ind < s.length();end_ind++){
                // copy(sub_start,sub_end,ostream_iterator<char>(cout,""));
                // cout<<endl;
                if(find(sub_start,sub_end,s[end_ind])!=sub_end){
                    this_len = distance(sub_start,sub_end);
                    max = this_len>max?this_len:max;
                    //  cout<< this_len<<endl;
                    sub_start = ++find(sub_start,sub_end,s[end_ind]);
                }// do nothing if the

                ++sub_end;
            }
            this_len = distance(sub_start,sub_end);
            max = this_len>max?this_len:max;
            // cout<<this_len;
            return max;
        }
    }
};

