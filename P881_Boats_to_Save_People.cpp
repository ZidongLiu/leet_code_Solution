//
// Created by Zidong Liu on 8/23/18.
//
#include <vector>
using namespace std;
/////// excellent solution beat the embeedd solution

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int n = people.size();
        if(n<=1){
            return(n);
        }else{
            sort(people.begin(),people.end());
            int i=0,j=n-1, ret_val =0;
            while(i<=j){
                int this_boat = people[j];
                for(;;){
                    if(this_boat+people[i]<=limit){
                        this_boat = this_boat + people[i];
                        i++;
                    }else{
                        ret_val++;
                        break;
                    }
                }
                j--;
            }
            return(ret_val);
        }

    }
};