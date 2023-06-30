#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int cap;
    int tp;
    int *st;
public:
    
    Stack(int capacity) {
        // Write your code here.
        st = new int[capacity];
        cap = capacity;
        tp=-1;
    }

    void push(int num) {
        // Write your code here.
        tp++;
        st[tp]=num;
    }

    int pop() {
        // Write your code here.
        if(tp==-1) return -1;
        return st[tp--];
    }
    
    int top() {
        // Write your code here.
        if(tp==-1) return -1;
        return st[tp];
    }
    
    int isEmpty() {
        // Write your code here.
        if(tp==-1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(tp==cap-1) return 1;
        return 0;
    }
    
};