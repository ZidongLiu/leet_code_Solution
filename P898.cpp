//
// Created by Zidong Liu on 9/1/18.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur1,cur2;
        int n=A.size();
        cur1.insert(A[0]);
        for(int i:A){
            cur1.insert(i);
            for(int j:cur1){
                cur2.insert(i|j);
                res.insert(i|j);
            }
            cur1 = cur2;
            cur2.clear();
        }
        return(res.size());
    }
};
