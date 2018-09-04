//
// Created by Zidong Liu on 9/3/18.
//

////////// beat 11%

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return(vector<TreeNode*>());
        }else{
            return(gen(1,n));
        }
    }

    vector<TreeNode*> gen(int start,int end){
        vector<TreeNode*> ret;
        if(start==end){
            ret.emplace_back(new TreeNode(start));
        }else if(start>end){
            ret.emplace_back(nullptr);
        }else{
            for(int i=start;i<=end;i++){
                vector<TreeNode*> left_node = gen(start,i-1);
                vector<TreeNode*> right_node = gen(i+1,end);
                for(auto left_elem:left_node){
                    for(auto right_elem:right_node){
                        TreeNode* this_node = new TreeNode(i);
                        this_node->left = left_elem;
                        this_node->right = right_elem;
                        ret.emplace_back(this_node);
                    }
                }
            }
        }
        return(ret);
    }
};