class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp = headA;
        ListNode* tail = nullptr;
        
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        tail = temp; // Now tail points to the last node of headA
        tail->next = headA; // Creating a loop
        
        ListNode* slow = headB;
        ListNode* fast = headB;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                ListNode* res = headB;
                
                while (res != slow) {
                    res = res->next;
                    slow = slow->next;
                }
                
                tail->next = nullptr; // Removing the loop in headA
                return res;
            }
        }
        
        tail->next = nullptr; // Removing the loop in headA
        return nullptr; // No intersection found
    }
};
