//
// Created by Zidong Liu on 8/24/18.
//
#include <vector>
#include <string>
using namespace std;


//// beat 100%
//// 0ms

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        if(n==0){
            return(words);
        }
        vector<string> ret_str;
        int left_ind = 0, right_ind = 0, this_len = words[0].length(), rest, num_space;
        int i=1;
        words.push_back("");
        int ind = 0;
        while(i<n){
            //cout<<i<<" leftind: "<<left_ind<<"   rightind: "<<right_ind<<endl;
            //cout<<"this_len: "<<this_len<<"   i_len: "<<words[i].length()<<endl;
            if(this_len+words[i].length()+1<=maxWidth){
                right_ind =i;
                this_len += words[i].length()+1;
            }else{

                rest = maxWidth - this_len;
                num_space = right_ind-left_ind;
                int ave_num = num_space==0?1:rest/num_space, modulus = num_space==0?rest:rest%num_space;
                //cout<<"rest: "<<rest<<"   num_space: "<<num_space<<"  ave: "<<ave_num<<"  mod: "<<modulus<<endl;

                string a(words[left_ind]);
                if(num_space==0){
                    string space(rest,' ');
                    a+=space;
                }
                for(int j=1;j<=num_space;j++){
                    string space(ave_num + (j<=modulus)+1,' ');
                    a += space;
                    a += words[left_ind+j];
                }

                //cout<<a<<endl;

                ret_str.push_back(a);

                /// update left and right and this_len

                left_ind = i;
                right_ind = i;
                this_len = words[i].length();
            }
            i++;
        }

        rest = maxWidth - this_len;
        string a(words[left_ind]);
        for(int j=left_ind+1;j<=right_ind;j++){
            a.push_back(' ');
            a += words[j];
        }
        string space(rest,' ');
        a += space;
        ret_str.push_back(a);

        return(ret_str);

    }
};