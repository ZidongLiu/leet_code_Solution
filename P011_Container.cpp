//
// Created by Zidong Liu on 5/29/18.
//


#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1,max_area=0,this_area;
        while(left<right){
            if(height[left] < height[right]){
                this_area = (right-left)*height[left];
                ++left;
            }else{
                this_area = (right-left)*height[right];
                --right;
            }
            if(this_area>max_area){
                max_area=this_area;
            }
        }
        return(max_area);
    }
};

