#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>
#include <unordered_set>
#include <limits>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};






int main(){
    Solution b;
    TreeNode *a= new TreeNode(-2147483648);
    ///a->right = new TreeNode();
    cout<<b.isValidBST(a);
}
