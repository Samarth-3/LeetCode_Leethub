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

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right){s.push(temp->right);}
            if(temp->left){s.push(temp->left);}
        }
       return ans; 
    }
    
};
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //moris traversal
        //threading
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{ //when left is not null move to rightmost part of left
                TreeNode* temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{ //case when temp->right pointing towards curr (thread)
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};