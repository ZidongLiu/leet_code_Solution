//
// Created by Zidong Liu on 6/1/18.
//

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<=3){
            int sum=0;
            for(auto elem:nums){
                sum += elem;
            }
            return(sum);
        }
        sort(nums.begin(),nums.end());
        /*
        for(auto elem:nums){
            cout<<elem<<"  ";
        }
        cout<<endl;
         */
        int closet = nums[0]+nums[1]+nums[nums.size()-1];
        int abs_dif = abs(closet-target);
        //cout<<"closet:"<<closet<<"   abs_dif:"<<abs_dif<<endl;
        if(abs_dif==0){
            return(target);
        }

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i-1]&&(i>0)){
                continue;///break the i loop
            }
            //cout<<"i:"<<i<<endl;
            int front = i+1, back = nums.size()-1,sum,dif;
            //cout<<"front:"<<front<<"   back:"<<back<<endl;
            while(front<back){
                if(nums[front]==nums[front-1]&&(front!=i+1)){
                    ++front;
                    continue;
                }
                if(nums[back]==nums[back+1]&&(back!=nums.size()-1)){
                    --back;
                    continue;
                }
                sum = nums[i] + nums[front] + nums[back];
                dif = (sum - target);
                //cout<<"1: "<<nums[i]<<"   2: "<<nums[front]<<"    3: "<<nums[back]<<"    dif: "<<dif<<"   abs_dif:"<<abs_dif<<endl;
                //cout<<"sum:"<<sum<<"   dif:"<<dif<<endl;
                if(dif==0){
                    return(target);
                }else if(dif<=-abs_dif){
                    ++front;
                }else if(dif>=abs_dif){
                    --back;
                }else{
                    closet = sum;
                    abs_dif = abs(dif);
                    if(abs(nums[i]+nums[front+1]+nums[back]-target)<abs(nums[i]+nums[front]+nums[back-1]-target)){
                        ++front;
                    }else{
                        --back;
                    }
                }
            }
        }
        return(closet);

    }
};