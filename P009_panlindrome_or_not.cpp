//
// Created by Zidong Liu on 5/28/18.
//
#include<vector>
using namespace std;


// get all digits

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return(0);
        }else{
            vector<int> int_elem;
            int thex = x;
            while(thex>0){
                int_elem.push_back(thex%10);
                thex/=10;
            }
            vector<int>::iterator left = int_elem.begin(),right = int_elem.end()--;
            for(int i=0;i<=(int_elem.size()/2);i++){
                if(*left!=*right){
                    return(0);
                }
            }
            return(1);
        }
    }
};



// reverse the string

class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x==0){
            return(1);
        }else if(x<0){
            return(0);
        }else if(x%10==0){
            return(0);
        }

        int rev=0;
        while(x>=rev){
            if(rev*10+x%10==x||rev==x){
                return(1);
            }else{
                rev = rev*10+x%10;
                x/=10;
            }
        }
        return(0);
    }
};

