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
    vector<vector<int>> result;
    vector<int> value;
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL){
            return result;
        }
        std::queue<TreeNode*> qCurrent;
        std::queue<TreeNode*> qNext;
        qCurrent.push(root);
        
        while(!qCurrent.empty())
        {
            while(!qCurrent.empty()){
                root = qCurrent.front();
                value.push_back(root->val);
                qCurrent.pop();
                if(root->left != NULL)
                {
                    qNext.push(root->left);
                }
                if(root->right != NULL)
                {
                    qNext.push(root->right);
                }
            }
            result.push_back(value);
            std::swap(qCurrent, qNext);
            value.clear();

        }
        return result;              
    }
};