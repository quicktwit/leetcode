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
    vector<int> postorderTraversal(TreeNode* root) {
        recursivePostOrder(root);
        return result;
    }
    
    void recursivePostOrder(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        recursivePostOrder(root->left);
        recursivePostOrder(root->right);
        result.push_back(root->val);
    }
};