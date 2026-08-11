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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root ==NULL)return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int s = que.size();
            vector<int> temp;

            for (int i = 0; i < s; i++) {
                TreeNode* n = que.front();
                que.pop();
               
                if (n->left != NULL) {
                    que.push(n->left);
                }
                if (n->right != NULL) {
                    que.push(n->right);
                }
                 temp.push_back(n->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};