/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    bool validate(TreeNode* root, long minVal, long maxVal){
        
        if(root == NULL)
            return true;

        // Check BST condition
        if(root->val <= minVal || root->val >= maxVal)
            return false;

        // Check left and right subtree
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        
        return validate(root, LONG_MIN, LONG_MAX);
    }
};