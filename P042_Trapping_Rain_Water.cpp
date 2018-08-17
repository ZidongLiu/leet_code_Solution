//
// Created by Zidong Liu on 8/16/18.
//

/// 8ms,
/// beat 64%

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2){
            return(0);
        }
        int ret_val =0;
        int left_ind,left_height, right_ind, right_height;
        left_ind = 0;
        left_height = height[0];
        for(int i=1;i<n;i++){
            if(height[i]>=left_height){
                right_ind = i;
                right_height = height[i];
                for(int j=left_ind+1;j < right_ind;j++){
                    ret_val += (left_height - height[j]);
                }
                left_ind = right_ind;
                left_height = right_height;
            }
        }

        int max_ind = left_ind;
        right_ind = n-1;
        right_height = height[n-1];
        for(int i=n-2; i >=max_ind; i--){
            if(height[i]>=right_height){
                left_ind = i;
                left_height = height[i];
                for(int j = right_ind-1;j>left_ind;j--){
                    ret_val+=(right_height-height[j]);
                }
                right_ind = left_ind;
                right_height = left_height;
            }
        }
        return(ret_val);
    }
};
