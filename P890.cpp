//
// Created by Zidong Liu on 8/18/18.
//
#include <vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode* node = new TreeNode(pre[i]);
            while (s.back()->val == post[j])
                s.pop_back(), j++;
            if (s.back()->left == NULL) s.back()->left = node;
            else s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }
    /*
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> ret_vec;
        ret_vec.push_back(new TreeNode(pre[0]));
        int j=0;
        for(int i=1;i<pre.size();i++){
            TreeNode* node = new TreeNode(pre[i]);
            while(post[j]==ret_vec.back()->val){
                j++;
                ret_vec.pop_back();
            }
            if(ret_vec.back()->left==NULL){
                ret_vec.back()->left = node;
            }else{
                ret_vec.back()->right = node;
            }
            ret_vec.push_back(node);
        }
        return(ret_vec[0]);
    }
     */
};