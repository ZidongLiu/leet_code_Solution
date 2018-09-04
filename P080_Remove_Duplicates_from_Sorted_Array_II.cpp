//
// Created by Zidong Liu on 8/27/18.
//
#include <vector>
using namespace std;
//////////// beat 100%
//////////// binary search solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return(n);
        }else{
            int cur = n-1, target = nums.back();
            while(cur>0){
                /*
                for(auto elem:nums){
                    cout<<elem<<"  ";
                }
                cout<<endl;
                 */
                cur = erase_this_num(cur,target,nums);
                target = nums[cur];
                ///cout<<"cur: "<<cur<<endl;
            }
            return(nums.size());
        }

    }

    int erase_this_num(int cur, int target, vector<int> &nums){//// nums[return+1]=target, nums[return] !=target
        int left = 0, right = cur, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                right = mid;
            }else if(nums[mid+1]!=target){
                left = mid+1;
            }else{
                if((cur-mid)>2){
                    nums.erase(nums.begin()+mid+3,nums.begin()+cur+1);
                }
                return(mid);
            }
            if(mid==0){
                break;
            }
        }
        if(mid==0){
            if(cur>1){
                nums.erase(nums.begin()+2,nums.begin()+cur+1);
            }
            return(0);
        }
    }
};