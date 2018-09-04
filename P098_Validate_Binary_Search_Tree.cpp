//
// Created by Zidong Liu on 9/3/18.
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/////////// beat 100%
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
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
