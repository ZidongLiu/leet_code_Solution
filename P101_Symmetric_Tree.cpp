//
// Created by Zidong Liu on 9/3/18.
//
////////////////// medium solution
////////////////// beat 98%

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
    bool isSymmetric(TreeNode* root) {
        return(compare_mirrow(root,root));
    }

    bool compare_mirrow(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2!=NULL || node1!=NULL && node2==NULL){
            return(0);
        }else if(node1==NULL && node2==NULL){
            return(1);
        }else{
            if(node1->val!=node2->val){
                return(0);
            }else{
                return(compare_mirrow(node1->left,node2->right) && compare_mirrow(node1->right,node2->left));
            }
        }
    }
};