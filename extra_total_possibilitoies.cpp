//
// Created by Zidong Liu on 6/3/18.
//
// Question: boys go to school, distance between the home and school is n meters.
// He could walk 1 meter or 2 meter in 1 step.
// However, because he is young, he can not take 2 consecutive 2 meters
// How many of possibilities are there for him to reach school

// Can be finished by back_track or combinatorics
class Solution{
public:
    int num_backtrack(int n){
        int num = 0;
        add_in(num,1,n);
        return(num);
    }

    int num_comb(int n){
        int q=0,num=0,p;
        while(1){
            p = n - 2*q;
            if(q>p+1){
                break;
            }else{
                num += NCR(p+1,q);
                q++;
            }
        }
        return(num);
    }
    void add_in(int &num, int carry, int n){
        if(n<0){
            return;
        }
        if(n==0){
            num+=1;
            return;
        }
        if(carry==1){
            add_in(num, 1, n-1);
            add_in(num, 2, n-2);
        }else{
            add_in(num, 1, n-1);
        }
    }

    int NCR(int n, int r)
    {
        if (r == 0) return 1;

        if (r > n/2) return NCR(n, n-r); // save some computation

        long res = 1;

        for(int k = 1; k <= r; ++k)
        {
            res *= n-k+1;
            res /= k;
        }

        return res;
    }
};