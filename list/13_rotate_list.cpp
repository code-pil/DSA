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
        if(head == NULL || head->next==NULL || k==0) return head;
        ListNode* tmp = head;
        int len=1;
        while(tmp->next != NULL) ++len, tmp=tmp->next;
        int end = len - k%len;
        tmp->next = head;
        while(end--) tmp = tmp->next;
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};
