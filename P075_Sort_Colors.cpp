//
// Created by Zidong Liu on 8/26/18.
//
#include <vector>
using namespace std;

///// good solution
///// beat 100%

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        if(n<=1){
            return;
        }
        int left=0, right = n-1, right_1 = n-1;
        while(nums[right]==2){
            right--;
            right_1--;
        }
        while(left<=right){
            /*
            cout<<"left: "<<left<<"  right: "<<right<<"   right_1: "<<right_1<<endl;
            cout<<endl;
            for(auto elem:nums){
                cout<<setw(4)<<elem;
            }
            cout<<endl;
             */
            switch(nums[left]){
                case 0:
                    left++;
                    break;
                case 1:
                    if(nums[right]==0){
                        swap(nums[left],nums[right]);
                        left++;
                        right--;
                    }else if(nums[right]==1){
                        right--;
                    }else{
                        swap(nums[right],nums[right_1]);
                        right_1--;
                        right--;
                    }
                    break;
                case 2:
                    if(nums[right]==0){
                        swap(nums[left],nums[right]);
                        swap(nums[right],nums[right_1]);
                        left++;
                        right_1--;
                        right--;
                    }else if(nums[right]==1){
                        swap(nums[left],nums[right_1]);
                        right_1--;
                        right--;
                    }else{
                        swap(nums[right],nums[right_1]);
                        right--;
                        right_1--;
                    }
                    break;
            }
        }

    }
};

//////// perfect solution
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(mid<=right){
            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[right], nums[mid]);
                right--;
            }
        }
    }
};