/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> result;
    vector<int> preorder(Node* root) {
        preOrderUtil(root);
        return result;
    }
    
    void preOrderUtil(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        result.push_back(root->val);
        for(Node* child:root->children)
        {
            preOrderUtil(child);
        }
    }
};