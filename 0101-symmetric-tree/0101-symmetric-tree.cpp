/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool mirror(TreeNode* l , TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL) return false;
        if(l->val!=r->val) return false;
        bool left=mirror(l->left,r->right);
        bool right=mirror(l->right,r->left);
        if(left && right) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left,root->right);
    }
};