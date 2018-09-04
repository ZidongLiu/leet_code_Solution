//
// Created by Zidong Liu on 9/1/18.
//
#include <vector>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {} };

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> asd;
        add(root,asd);
        TreeNode *ret_end = new TreeNode(asd[0]), *ret;
        ret = ret_end;
        for(int i=1;i<asd.size();i++){
            ret_end->right = new TreeNode(asd[i]);
            ret_end = ret_end->right;
        }
        return(ret);
    }

    void add(TreeNode* root, vector<int> &asd){
        if(root->left!=NULL){
            add(root->left,asd);
        }
        asd.push_back(root->val);
        if(root->right !=NULL){
            add(root->right,asd);
        }
    }
};