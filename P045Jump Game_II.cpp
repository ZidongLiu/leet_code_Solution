//
// Created by Zidong Liu on 8/17/18.
//

#include <vector>
using namespace std;
//// dp solution, time limit exceed
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        if(n==1){
            return(0);
        }else{
            vector<int> dp_jump(n-1);
            dp_jump.back() = 1;
            for(int i=n-3;i>=0;i--){
                int min_this = n;
                int upper;
                if(i+nums[i]<=n-2){
                    upper = i+nums[i];
                }else{
                    upper = n-2;
                }
                for(int j=i+1;j<=upper;j++){
                    if(dp_jump[j]+1<min_this){
                        min_this = dp_jump[j] +1;
                    }
                }
                dp_jump[i] = min_this;
            }
            return(dp_jump[0]);
        }

    }
};


/// elegant single loop solution
/// take the concept of intersecting jump
/// So great, median, beat 97.8%, 8ms
class Solution {
public:
    int jump(vector<int>& nums) {
        int jp =0, last_max=0, max=0;
        for(int i=0;i<nums.size()-1;i++){
            max = max > (i+nums[i])? max:(i+nums[i]);
            if(i==last_max){
                jp++;
                last_max = max;
            }
        }
        return(jp);
    }
};