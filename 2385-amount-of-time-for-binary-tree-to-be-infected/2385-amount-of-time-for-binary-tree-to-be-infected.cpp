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
    int findMaxDistance(map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;
        int maxi = 0;
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    flag = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    flag = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (mpp[node] && !visited[mpp[node]]) {
                    flag = true;
                    visited[mpp[node]] = true;
                    q.push(mpp[node]);
                }
            }
            if (flag) {
                maxi++;
            }
        }
        return maxi;
    }

    TreeNode* bfstoMapParent(TreeNode* root, map<TreeNode*, TreeNode*>& mpp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        while (!q.empty()) {
            auto node = q.front();
            if (node->val == start) {
                res = node;
            }
            q.pop();
            if (node->left) {
                q.push(node->left);
                mpp[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = bfstoMapParent(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }
};