//slow fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//naive 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int x=0;
        ListNode* ptr=head;
        while(ptr){
            x++;
            ptr=ptr->next;
        }
        x/=2;
        x++;
        ptr=head;
        while(--x) {
            ptr=ptr->next;
        }
        return ptr;
    }
};
