//
// Created by Zidong Liu on 8/19/18.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}};

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