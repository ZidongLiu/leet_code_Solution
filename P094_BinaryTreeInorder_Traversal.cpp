//
// Created by Zidong Liu on 9/3/18.
//

//
// Created by Zidong Liu on 9/3/18.
//
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorderAdd(root,ret);
        return(ret);
    }
    void inorderAdd(TreeNode* node, vector<int> &ret){
        if(node->left!=NULL){
            inorderAdd(node->left,ret);
        }
        ret.push_back(node->val);
        if(node->right!=NULL){
            inorderAdd(node->right,ret);
        }
    }
};