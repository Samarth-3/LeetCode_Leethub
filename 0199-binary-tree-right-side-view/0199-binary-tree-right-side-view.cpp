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
void solve(TreeNode* root, vector<int> &ans, int level) {
   // base case
   if(root == NULL)
       return ;
   
   // we entered in new level if below condition is true
   if(level == ans.size())
       ans.push_back(root -> val);
   
   solve(root -> right, ans, level + 1);
    solve(root -> left, ans, level + 1);
}
public:
    
    vector<int> rightSideView(TreeNode* root) {
          vector<int> ans;
          solve(root, ans, 0);
          return ans;
    }
};