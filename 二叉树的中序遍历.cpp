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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        if(root != nullptr) {
            stack<TreeNode *> stack;
            while(!stack.empty() || root != nullptr) {
                if(root != nullptr) {
                    stack.push(root);
                    root = root->left;
                } else {
                    root = stack.top();
                    stack.pop();
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};