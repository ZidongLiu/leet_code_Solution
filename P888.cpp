//
// Created by Zidong Liu on 8/18/18.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa= 0, sb=0;
        for(auto elem:A){
            sa+=elem;
        }
        for(auto elem:B){
            sb+=elem;
        }
        vector<int> ret_vec;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i]-B[j]==(sa-sb)/2){
                    ret_vec={A[i],B[j]};
                    return(ret_vec);
                }
            }
        }
        return(ret_vec);
    }
};