//206. Reverse Linked List

//Given the head of a singly linked list, reverse the list, and return the reversed list.



 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode *p=NULL,*n=NULL,*c=head;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
            
        }
        return p;
    }
};