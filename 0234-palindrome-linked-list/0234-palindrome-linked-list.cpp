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
private:
    ListNode* reverse(ListNode* slow){
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool checkPal(ListNode* head,ListNode* slow){
        ListNode* temp=head;
        while(slow != nullptr && temp != nullptr){
            if(temp->val!=slow->val){
                return false;
            }
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true; // Empty list or single node is a palindrome
        }
        if(head->next->next==NULL){
            if(head->val==head->next->val){
                return true;
            }
            return 0;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        ListNode* rev=reverse(slow);
        return checkPal(head,rev);
    }
};