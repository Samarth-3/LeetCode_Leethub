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
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minIndex=q.front().second;
            int first;
            int last;
            for(int i=0;i<size;i++){
                long int curID=q.front().second-minIndex;
                TreeNode* node=q.front().first;
                q.pop();
                if (i==0){first=curID;}
                if (i==size-1){last=curID;}
                if(node->left){
                    q.push({node->left,curID*2+1});
                }
                if(node->right){
                    q.push({node->right,curID*2+2});
                }
                ans=max(ans,last-first+1);
            }
        }
        return ans;
    }
};