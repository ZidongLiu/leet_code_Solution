//
// Created by Zidong Liu on 9/1/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return(ismono(A,0,A.size()));
    }

    bool ismono(vector<int> &A, int left_ind, int right_ind){
        if(left_ind==right_ind){
            return(1);
        }else if(left_ind==right_ind-1){
            return(A[left_ind]<=A[right_ind]);
        }else{
            int mid = (left_ind+right_ind)/2;
            return(A[mid]<=A[mid+1] && ismono(A,left_ind,mid) && ismono(A,mid+1,right_ind));
        }
    }
};