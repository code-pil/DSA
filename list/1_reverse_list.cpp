
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


//recursive 
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
};

//iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* p=head,*q=head->next,*r=NULL;
        while(p){
            p->next=r;
            r=p;
            p=q;
            if(q)
                q=q->next;
        }
        return r;
    }
};
