/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int mx=0;
int length(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(length(root->left),length(root->right));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=length(root->left)+length(root->right);
        mx=max(mx,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return mx;
    }
};