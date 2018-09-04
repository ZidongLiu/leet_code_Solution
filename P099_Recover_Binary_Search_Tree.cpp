//
// Created by Zidong Liu on 9/3/18.
//
#include <vector>
#include <limits>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



////// brute force solution
////// AC, 1620ms, beat 0%

class Solution1 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes = tree2nodevec_inorder(root);
        for(int i=0;i<nodes.size();i++){
            for(int j=i+1;j<nodes.size();j++){
                swap(nodes[i],nodes[j]);
                if(isValidBST(root)){
                    break;
                }
                swap(nodes[i],nodes[j]);
            }
        }
    }

    vector<TreeNode*> tree2nodevec_inorder(TreeNode* root){
        vector<TreeNode*> ret;
        inorder_add(root,ret);
        return(ret);
    }

    void inorder_add(TreeNode* root, vector<TreeNode*> &ret){
        if(root!=NULL){
            inorder_add(root->left,ret);
            ret.push_back(root);
            inorder_add(root->right,ret);
        }
    }

    void swap(TreeNode* a, TreeNode* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    bool isValidBST(TreeNode* root) {
        return(valid_or_not(root,n_inf,inf,0,0));
    }

    bool valid_or_not(TreeNode* node, int lower, int upper, bool reach_lower, bool reach_upper){
        if(node==NULL){
            return(1);
        }else{
            ///cout<<"node: "<<node->val<<"  lower:  "<<lower<<"   upper: "<<upper<<"  reach_lower: "<<reach_lower<<"   reach_upper:  "<<reach_upper<<endl;
            if(node->val==inf){
                if(reach_upper){
                    return(0);
                }else{
                    if(upper < inf){
                        return(0);
                    }
                    return(node->val >lower && valid_or_not(node->left,lower,inf,reach_lower,1) && valid_or_not(node->right,inf,upper,reach_lower,1));
                }
            }
            if(node->val ==n_inf){
                if(reach_lower){
                    return(0);
                }else{
                    if(lower>n_inf){
                        return(0);
                    }
                    return(node->val < upper && valid_or_not(node->left,lower,n_inf,1,reach_upper) && valid_or_not(node->right,n_inf,upper, 1,reach_upper));
                }
            }
            return(node->val < upper && node->val > lower && valid_or_not(node->left,lower,node->val,reach_lower,reach_upper) && valid_or_not(node->right,node->val,upper,reach_lower,reach_upper));
        }

    }

    int inf = numeric_limits<int>::max();
    int n_inf = numeric_limits<int>::min();
};

////////////////////////////////////// traversal inorder solution
////////////////////////////////////// medium solution
class Solution {
public:
    TreeNode *first_node = NULL;
    TreeNode *second_node = NULL;
    TreeNode *prev_node = new TreeNode(numeric_limits<int>::min());

    void recoverTree(TreeNode* root) {
        traverseInorder(root);
        int temp = first_node->val;
        first_node->val = second_node->val;
        second_node->val = temp;
    }

    void traverseInorder(TreeNode* node){
        if(node==NULL){
            return;
        }else{
            traverseInorder(node->left);
            if(first_node==NULL && node->val < prev_node->val){
                first_node = prev_node;
            }
            if(first_node!=NULL && node->val < prev_node->val){
                second_node = node;
            }
            prev_node = node;
            traverseInorder(node->right);
        }
    }
};