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

//WIHT Hash Map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* tmp = head,*root = newHead;
        unordered_map<Node*,Node*> mp;
        mp[NULL]=NULL;
        while(tmp!=NULL){
            Node* NEW = new Node(tmp->val);
            root->next = NEW;
            root = root->next;
            mp[tmp]=root;
            tmp = tmp->next;
        }
        root = newHead->next;
        tmp = head;
        while(tmp!=NULL){
            root->random = mp[tmp->random];
            tmp = tmp->next;
            root = root->next;
        }
        return newHead->next;
    }
};


// without HASH MAP Approach
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr = head;
        Node* front = head;
        while(itr != NULL){
            front = itr->next;
            Node* copy = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        itr = head;
        while(itr!=NULL){
            if(itr->random != NULL){
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        itr=head;
        front=head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;

        while(itr!=NULL){
            front = itr->next->next;
            copy->next = itr->next;
            itr->next = front;
            copy = copy->next;
            itr = front;
        }

        return pseudoHead->next;
    }
};
