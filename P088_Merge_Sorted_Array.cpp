//
// Created by Zidong Liu on 8/31/18.
//
#include <vector>
using namespace std;
//////////// medium solution
//////////// beat 98%

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_1 = m-1, index_2 = n-1, index_cur = m+n-1;
        while(index_1>=0 &&index_2>=0){
            ///cout<<"index_1:  "<<index_1<<"  index_2: "<<index_2<<endl;
            if(nums1[index_1]>=nums2[index_2]){
                nums1[index_cur] = nums1[index_1];
                index_1--;
            }else{
                nums1[index_cur] = nums2[index_2];
                index_2--;
            }
            index_cur--;
        }

        if(index_1 < 0){
            while(index_cur>=0){
                nums1[index_cur] = nums2[index_2];
                index_2--;
                index_cur--;
            }
        }

        nums1.erase(nums1.begin()+m+n,nums1.end());
    }
};