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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        queue<pair<TreeNode*,long long>>que;
        que.push({root,0});
        long long ans =0;
        while(!que.empty()){
            int size = que.size();
            long long first,last;
            long long mini = que.front().second;
            for(int i=0;i<size;i++){
                long long curIdx = que.front().second-mini;
                TreeNode* node = que.front().first;
                que.pop();
                if(i==0){
                    first = curIdx;
                }
                if(i==size-1){
                    last = curIdx;
                }
                if(node->left){
                    que.push({node->left,curIdx*2+1});

                }    
                if(node->right){
                    que.push({node->right,curIdx*2+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};