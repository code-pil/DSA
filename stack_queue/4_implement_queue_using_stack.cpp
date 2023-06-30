
/*

Two stack Approachs

Editorial -- > https://leetcode.com/problems/implement-queue-using-stacks/editorial/

*/




class MyQueue {
public:

    stack<int> s1, s2;
    int front;
    
    void push(int x) {
        if(s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty()) return front;
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */