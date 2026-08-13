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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {

            int s = que.size();
            for (int i = 0; i < s; i++) {
                TreeNode* n = que.front();
                que.pop();
                if (i == s - 1)
                    ans.push_back(n->val);
                if (n->left)
                    que.push(n->left);
                if (n->right)
                    que.push(n->right);
            }
        }
        return ans;
    }
};