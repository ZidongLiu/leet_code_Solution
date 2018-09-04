//
// Created by Zidong Liu on 9/3/18.
//

#include <iostream>
#include <vector>
using namespace std;
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Treeprint{
public:
    static void print_preorder(TreeNode* tree){
        cout<<tree->val<<"  ";
        if(tree->left!=NULL){
            print_preorder(tree->left);
        }
        if(tree->right!=NULL){
            print_preorder(tree->right);
        }
    }

    static void print_inorder(TreeNode* tree){
        if(tree->left!=NULL){
            print_inorder(tree->left);
        }
        cout<<tree->val<<"  ";
        if(tree->right!=NULL){
            print_inorder(tree->right);
        }
    }

    static void print_postorder(TreeNode* tree){

        if(tree->left!=NULL){
            print_postorder(tree->left);
        }
        if(tree->right!=NULL){
            print_postorder(tree->right);
        }
        cout<<tree->val<<"  ";
    }
};

TreeNode* copyInorder(TreeNode* node){
    TreeNode* ret;
    if(node==NULL){
        return(NULL);
    }else{
        ret->left = copyInorder(node->left);
        ret->val = node->val;
        ret->right = node->right;
    }
}
*/
/*
TreeNode* generateTree(vector<int> a){
    if(a.size()==0){
        return(NULL);
    }
    TreeNode* ret = new TreeNode(a[0]);
    vector<TreeNode*> working, working2;
    working.push_back(ret);
    int ind=1;
    while(ind<a.size()){
        for(auto elem:working){
            if(a[ind]!=NULL){
                elem->left = new TreeNode(a[ind]);
                working2.push_back(elem->left);
            }
            if(a[ind+1]!=NULL){
                elem->right = new TreeNode(a[ind+1]);
                working2.push_back(elem->right);
            }
            ind+=2;
        }
        working = working2;
        working2.clear();
    }
    return(ret);
}
 */