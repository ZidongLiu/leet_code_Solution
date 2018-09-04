//
// Created by Zidong Liu on 8/18/18.
//
#include <vector>
using namespace std;
////////// median, beat 100%
///////// 40ms

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ret_vec;
        vector<int> max_candidate(4);
        max_candidate[0] = r0;
        max_candidate[1] = (R-1-r0);
        max_candidate[2] = c0;
        max_candidate[3] = (C-1-c0);
        int max_level = *max_element(max_candidate.begin(),max_candidate.end());
        ret_vec.push_back({r0,c0});

        for(int level = 1; level<=max_level;level++){
            c0++;
            if(r0>=0&&r0<R&&c0>=0&&c0<C){
                ret_vec.push_back({r0,c0});
            }

            int dist = ((2*level+1)*(2*level+1) - (2*(level-1)+1)*(2*(level-1)+1))/4;

            for(int ind=1;ind<=4;ind++){
                for(int j=1;j<=(ind==1?dist-1:dist);j++){

                    if(ind==1){
                        ++r0;
                    }else if(ind==2){
                        --c0;
                    }else if(ind==3){
                        --r0;
                    }else{
                        ++c0;
                    }
                    if(r0>=0&&r0<R&&c0>=0&&c0<C){
                        ret_vec.push_back({r0,c0});
                    }
                }

            }

        }
        return(ret_vec);
    }
};