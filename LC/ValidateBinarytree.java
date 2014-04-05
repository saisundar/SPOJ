/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *last = NULL;
public:
    bool isValidBST(TreeNode *root) {
        if(root==NULL){
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }
        if(last!=NULL && (last->val >= root->val)){
            return false;
        }
        last=root;
        if(!isValidBST(root->right)){
            return false;
        }
        return true;
    }
};