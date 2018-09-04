//
// Created by Zidong Liu on 8/29/18.
//
#include <vector>
using namespace std;
//////// 2d dp approach, memory limit exceed

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return(0);
        }else{
            vector<int> row(n,0);
            vector<vector<int>> dp(n,row);
            for(int i=0;i<n;i++){
                dp[i][i] = heights[i];
                for(int j=i+1;j<n;j++){
                    if(dp[i][j-1]<=heights[j]){
                        dp[i][j] = dp[i][j-1];
                    }else{
                        dp[i][j] = heights[j];
                    }
                }
            }
            int ret_max = 0, this_val;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    this_val = dp[i][j] * (j-i+1);
                    if(this_val>ret_max){
                        ret_max = this_val;
                    }
                }
            }
            return(ret_max);
        }
    }
};


/////// dp solution is too naive, it seems to be good but not
/////// beat 19.4%, worst case is still n^2 complexity

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return(0);
        }else{
            vector<int> leftbound(n), rightbound(n);
            leftbound[0] = -1;
            int p;
            for(int i=1;i<n;i++){
                p = i-1;
                while(p>=0 && heights[p]>=heights[i]){
                    p = leftbound[p];
                }
                leftbound[i] = p;
            }
            rightbound[n-1] = n;
            for(int i=n-2;i>=0;i--){
                p = i+1;
                while(p<=n-1 && heights[p]>=heights[i]){
                    p = rightbound[p];
                }
                rightbound[i] = p;
            }
            /*
            for(auto elem:leftbound){
                cout<<elem<<"  ";
            }
            cout<<endl;
            for(auto elem:rightbound){
                cout<<elem<<"  ";
            }
            cout<<endl;
             */
            int max_are = 0, this_val;
            for(int i=0;i<n;i++){
                this_val = heights[i] *(rightbound[i]-leftbound[i]-1);
                ///cout<<this_val<<endl;
                if(this_val>max_are){
                    max_are = this_val;
                }
            }
            return(max_are);
        }
    }
};




///// original idea
///// beat 29%
///// idea from the 100% solution, not bad
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return(0);
        }else{
            vector<int> cur_height, cur_index;
            int max_area = 0;

            for(int i=0;i<n;i++){
                ///cout<<"i"<<i<<endl;
                if(cur_height.empty() || cur_height.back() < heights[i]){
                    cur_height.push_back(heights[i]);
                    cur_index.push_back(i);
                }else{
                    int cur_n = cur_height.size(), temp;
                    for(int j=cur_n-1;j>=0;j--){
                        if(cur_height[j]>=heights[i]){
                            max_area = max(max_area,cur_height.back()*(i-cur_index.back()));
                            temp = cur_index[j];
                            cur_height.pop_back();
                            cur_index.pop_back();
                        }else{
                            break;
                        }
                    }
                    cur_height.push_back(heights[i]);
                    cur_index.push_back(temp);
                }
                /*
                for(auto elem:cur_height){
                    cout<<elem<<"  ";
                }
                cout<<endl;
                for(auto elem:cur_index){
                    cout<<elem<<"  ";
                }
                cout<<endl;
                 */
            }

            while(!cur_height.empty()){
                max_area = max(max_area, cur_height.back()*(n-cur_index.back()));
                cur_height.pop_back();
                cur_index.pop_back();
            }
            return(max_area);
        }
    }
};