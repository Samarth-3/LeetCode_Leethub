/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next; // Save the pointer to the next node
        node->val = nextNode->val; // Copy the value of the next node to the current node
        node->next = nextNode->next; // Update the next pointer of the current node to skip the next node
        
        delete nextNode;
    }
};