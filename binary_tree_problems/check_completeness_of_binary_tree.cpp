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
public:
    int number = 0;
    bool isCompleteTree(TreeNode* root) {
        countNodes(root);
        return isCompleteTreeUtil(root, 0);
    }
    
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        number++;
        countNodes(root->left);
        countNodes(root->right);
        return 0;
    }
    bool isCompleteTreeUtil(TreeNode* root, int index)
    {
        if(root == NULL)
        {
            return true;
        }
        if(index >= number)
        {
            return false;
        }
        return isCompleteTreeUtil(root->left, index*2 + 1) && 
            isCompleteTreeUtil(root->right, index*2 + 2);
    }
};