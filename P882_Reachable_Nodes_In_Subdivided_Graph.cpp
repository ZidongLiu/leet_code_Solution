//
// Created by Zidong Liu on 8/23/18.
//
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
/////// solution using back_track
/////// not pass for the following test case

/*vector<vector<int>> edges =  {{1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}};
int  M = 17, N = 5;
cout<<a.reachableNodes(edges,M,N);*/


class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> row(N,0);
        vector<vector<int>> obst(N,row), reach(N,row);
        reach[0][0]=1;
        for(int i=0;i<N;i++){
            obst[i][i] = 1;
        }

        for(auto elem: edges){
            obst[elem[0]][elem[1]] = elem[2];
            obst[elem[1]][elem[0]] = elem[2];
        }

        for(auto elem:obst){
            for(auto elem2:elem){
                cout<<setw(5)<<elem2;
            }
            cout<<endl;
        }
        cout<<endl;

        backtrack(0,obst,reach,N,M);

        for(auto elem:reach){
            for(auto elem2:elem){
                cout<<setw(5)<<elem2;
            }
            cout<<endl;
        }
        cout<<endl;


        int ret=0;
        for(int i=0;i<N;i++){
            ret += reach[i][i];
            cout<<ret<<"  ";
            for(int j=i+1;j<N;j++){
                ret+= min(reach[i][j]+reach[j][i],obst[i][j]);
                cout<<ret<<"  ";
            }
            cout<<endl;
        }

        return(ret);
    }
    void backtrack(int start,vector<vector<int>> &obst, vector<vector<int>> &reach, int &N, int M){
        for(int i=0;i<N;i++){
            if(i!=start){
                if(M > obst[start][i]){
                    reach[start][i] = obst[start][i];
                    reach[i][i] = 1;
                    backtrack(i,obst,reach,N,M-obst[start][i]-1);
                }else{
                    reach[start][i] = max(reach[start][i],M);
                }
            }
        }
    }
};
