//
// Created by Zidong Liu on 5/30/18.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return("");
        }
        if(strs.size()==1){
            return(strs[0]);
        }
        for(string elem : strs){
            if(elem.compare("")==0){
                return("");
            }
        }
        // cout<<"here"<<endl;
        // cout<<strs.size()<<endl;
        vector<int> len;
        string ret_str,cur;
        for(int i=0; i<strs.size();i++){
            len.push_back(strs[i].length());
        }
        int min_len = *min_element(len.begin(),len.end());
        //cout<<min_len<<endl;
        for(int i=0;i<min_len;i++){
            cur.clear();
            for(auto elem: strs){
                cur.push_back(elem[i]);
            }
            //cout<<cur<<endl;
            if(distance(cur.begin(),unique(cur.begin(),cur.end()))==1){
                ret_str.push_back(strs[0][i]);
            }else{
                break;
            }
        }
        return(ret_str);

    }
};

