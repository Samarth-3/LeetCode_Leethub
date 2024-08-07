/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL || head->next == NULL) {
            return head;
        }
        
        // Compute the length of the list
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        
        // Compute the effective rotation steps
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }
        
        // Find the new head after rotation
        int stepsToNewHead = length - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }
        
        // New head and break the list
        ListNode* newHead = temp->next;
        temp->next = NULL;
        
        // Find the last node of the rotated part
        ListNode* lastNode = newHead;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        
        // Attach the old head to the end of the rotated part
        lastNode->next = head;
        
        return newHead;
    }
};
