class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Count the remaining nodes
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count == k) {
            // Reverse the next k nodes and connect the reversed sublist
            curr = reverseKGroup(curr, k);
            
            // Reverse the current group of k nodes
            while (count > 0) {
                ListNode* next = head->next;
                head->next = curr;
                curr = head;
                head = next;
                count--;
            }
            
            head = curr; // Update head to the new head of the reversed group
        }

        return head;
    }
};
