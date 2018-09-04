//
// Created by Zidong Liu on 5/26/18.
//


#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A,B;
        if(nums1.size()<nums2.size()){
            A = nums1;
            B = nums2;
        }else{
            A = nums2;
            B = nums1;
        }
        // initialization
        int m = A.size(),n=B.size();
        int left=0,right=m-1,i,j,exit_flag=0;
        double ret,ret_left,ret_right;
        if(m==0){
            right = n-1;
            i = (left+right)/2;
            if(n%2==0){
                return((double(B[i])+double(B[i+1]))/2);
            }else{
                return(double(B[i]));
            }
        }
        if(m==1){
            if(n==1){
                return((double(A[0])+double(B[0]))/2);
            }else if(n==2){
                if(A[0]<B[0]){
                    return(double(B[0]));
                }else if(A[0]<B[1]){
                    return(double(A[0]));
                }else{
                    return(double(B[1]));
                }
            }else{
                i = 0;
                j = (m+n)/2 - 2 - i;
                if(A[i]>B[j+1]){
                    if((m+n)%2==0){
                        ret_left = double(B[j+1]);
                        ret_right = min(double(A[i]),double(B[j+2]));
                        return((ret_left+ret_right)/2);
                    }else{
                        ret = min(double(A[i]),double(B[j+2]));
                        return(ret);
                    }
                }else{
                    if((m+n)%2==0){
                        ret_left = max(double(B[j]),double(A[i]));
                        ret_right = double(B[j+1]);
                        return((ret_left+ret_right)/2);
                    }else{
                        ret = double(B[j+1]);
                        return(ret);
                    }
                }
            }
        }
        while(1){
            i = (left+right)/2;
            j = (m+n)/2 - i - 2;
            //cout<<"left: "<<left<<endl;
            //cout<<"right: "<<right<<endl;
            if(A.at(i)>B.at(j+1)){/// check if B[j+1] exist
                right = i;
                if(right==0){
                    exit_flag = 2;
                    break;
                }
                continue;
            }else if(B.at(j)>A.at(i+1)){ /// check if A[i+1] exist
                left = i;
                if(left==(m-2)){
                    exit_flag = 3;
                    break;
                }
                continue;
            }else{
                exit_flag = 1;
                break;
            }
        }
        //cout<<"exit: "<<exit_flag<<endl;

        if(exit_flag==1){
            if((m+n)%2==0){
                ret_left = max(double(A[i]),double(B[j]));
                ret_right = min(double(A[i+1]),double(B[j+1]));
                return((ret_left+ret_right)/2);
            }else{
                ret = min(double(A[i+1]),double(B[j+1]));
                return(ret);
            }
        }else if(exit_flag==2){/// A[0]>B[j+1]
            if((m+n)%2==0){
                ret_left = double(B[j+1]);
                if(j+2<=(n-1)){
                    ret_right = min(double(A[0]),double(B[j+2]));
                }else{
                    ret_right = double(A[0]);
                }
                //cout<<"ret_right: "<<ret_right<<endl;
                return((ret_left+ret_right)/2);
            }else{
                ret = min(double(A[i]),double(B[j+2]));
                return(ret);
            }
        }else{/// i==m-2 and ,m-2 has failed ,,B.at(j)>A.at(i+1)
            if((m+n)%2==0){
                ret_left = max(double(A[i+1]),double(B[j-1]));
                ret_right = double(B[j]);
                return((ret_left+ret_right)/2);
            }else{
                ret = double(B[j]);
                return(ret);
            }
        }
    }
};



