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

    ListNode* reverse(ListNode* head){
        ListNode* p=head, *q=head, *r=NULL;
        while(p!=NULL){
            q=p->next;
            p->next=r;
            r=p;
            p=q;
        }
        return r;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head, *fast=head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow=slow->next;
        fast=head;
        while(slow!=NULL){
            if(slow->val != fast->val) return false;
            slow=slow->next,fast=fast->next;
        }
        return true;
    }
};
