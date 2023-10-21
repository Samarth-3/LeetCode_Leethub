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
    vector<int> postorderTraversal(TreeNode* root) {
        //using one stack 
    vector<int>ans;
    stack<TreeNode*>s;
    while(!s.empty() || root!=NULL){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            TreeNode* temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                ans.push_back(temp->val);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                root=temp;
            }
        }   
    }
    return ans;
        
        //solution using 2 stacks
       /* vector<int> ans;
        if(root==NULL){return ans;}
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* temp=s1.top();
            s2.push(temp);
            s1.pop();
            if(temp->left!=NULL){s1.push(temp->left);}
            if(temp->right!=NULL){s1.push(temp->right);}
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
        */
    }
};