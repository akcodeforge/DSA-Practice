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
    vector<int> Node(TreeNode* root, int n) {
        vector<int> ans;
        if (root == NULL) {
            ans.push_back(INT_MIN);
            return ans;
        }
        ans.push_back(root->val);
        vector<int> left = Node(root->left, n);
        vector<int> right = Node(root->right, n);
        if(n==1){
            ans.insert(ans.end(),left.begin(),left.end());
            ans.insert(ans.end(),right.begin(),right.end());
        }
        if(n==2){
            ans.insert(ans.end(),right.begin(),right.end());
            ans.insert(ans.end(),left.begin(),left.end());

        }
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        vector<int> left;
        vector<int> right;
        left = Node(root->left, 1);
        right = Node(root->right, 2);
        if (left.size() != right.size())
            return false;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }
};