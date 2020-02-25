/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

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
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        recursiveInorderTraversal(root);
        return result;
    }
    
    void recursiveInorderTraversal(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
    }
};