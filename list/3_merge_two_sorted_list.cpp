class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val > list2->val) swap(list1,list2);
        ListNode* tmp = list1;
        ListNode* ans = tmp;
        list1=list1->next;
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                tmp->next = list2;
                tmp = tmp->next;
                list2=list2->next;
            }
            else{
                tmp->next = list1;
                tmp=tmp->next;
                list1=list1->next;
            }
        }
        if(list1!=NULL) tmp->next=list1;
        if(list2!=NULL) tmp->next=list2;
        return ans;
    }
};
