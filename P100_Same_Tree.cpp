//
// Created by Zidong Liu on 9/3/18.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q!=NULL || p!=NULL && q==NULL){
            return(0);
        }else if(p==NULL && q==NULL){
            return(1);
        }else{
            if(p->val !=q->val){
                return(0);
            }else{
                return(isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
            }
        }
    }
};