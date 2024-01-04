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
class BSTIterator{
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode *root, int flag){
        if (flag == 1){
            while (root != NULL){
                st.push(root);
                root = root->right;
            }
        }
        else {
            while (root != NULL){
                st.push(root);
                root = root->left;
            }
        }
    }
    
    int next(){
        TreeNode *currNode = st.top();
        st.pop();
        if (currNode->right != NULL){
            TreeNode *temp = currNode->right;
            while (temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
        }
        return currNode->val;
    }
    
    int before(){
        TreeNode *currNode = st.top();
        st.pop();
        if (currNode->left != NULL){
            TreeNode *temp = currNode->left;
            while (temp != NULL){
                st.push(temp);
                temp = temp->right;
            }
        }
        return currNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        BSTIterator l(root, 0);  //next
        BSTIterator r(root, 1);  //before
        
        int i = l.next();
        int j = r.before();
        
        while (i < j){
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.before();
        }
        return false;
    }
};