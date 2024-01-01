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
    TreeNode* help(vector<int>& preorder,int &index,int bound){
        if(index==preorder.size() || preorder[index]>bound ){
            return NULL;
        }
        TreeNode* temp=new TreeNode(preorder[index++]);
        temp->left=help(preorder,index,temp->val);
        temp->right=help(preorder,index,bound);
        
        return temp;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return help(preorder,index,INT_MAX);
    }
};