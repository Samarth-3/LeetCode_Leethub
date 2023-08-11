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
   ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }       
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        //merging sorted ll
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        while(left!=NULL){
                temp -> next = left;
                temp = left;
                left = left -> next;
        }
        while(right!=NULL){
                temp->next=right;
                temp=right;
                right=right->next;
        }
        ans=ans->next;
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        //recursive call to sllit linked list and sort them
        left=sortList(left);
        right=sortList(right);
        
        //merging and return ans
        ListNode* result=merge(left,right);
        return result;
    }
};