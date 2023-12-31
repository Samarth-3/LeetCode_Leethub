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
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (true) {
            if (current != NULL) {
                s.push(current);
                current = current->left;
            }
            else{
                if(s.empty()){
                    break;
                }
                current = s.top();
                s.pop();
                ans.push_back(current->val);
                current = current->right;
            } 
        }
        return ans;
    }
};
