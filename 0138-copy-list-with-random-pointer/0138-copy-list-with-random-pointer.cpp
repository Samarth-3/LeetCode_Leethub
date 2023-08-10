/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newNode=new Node(d);
        //if list is empty
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp=head;
        //cloning list with next values
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        //mapping 
        unordered_map<Node* ,Node*> oldtonew;
        Node* originalNode=head;
        Node* cloneNode=clonehead;
        while(originalNode!=NULL){
            oldtonew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        //cloning random pointers
        originalNode=head;
        cloneNode=clonehead;
        while(originalNode!=NULL){
            cloneNode->random=oldtonew[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return clonehead;
    }
};