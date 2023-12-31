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
    void help(TreeNode* node,vector<string> &ans,vector<int> &s){    
        if(node==NULL){
            return;
        }
        s.push_back(node->val);
        if(node->left==NULL && node->right==NULL){ 
            string pathstr;
            for(int i=0;i<s.size();i++){
                pathstr+=to_string(s[i]);
                if(i<s.size()-1){
                    pathstr+="->";
                }
            }
            ans.push_back(pathstr);
        }
        else{
            help(node->left,ans,s);
            help(node->right,ans,s);
        }
        s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> s;
        help(root,ans,s);
        return ans;
    }
};
