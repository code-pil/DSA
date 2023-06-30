/*


Approachs using two queues

sol 1: push: o(n), pop: o(1)

stack |   |
      | 2 |
      | 1 |


push(3) 

                                                         s
q1 : | 2 | 1 |    q1 : | 2 | 1 |    q1 : |  |            w   q1 : | 3 | 2 | 1 |
q2 : |   |        q2 : | 3 |        q2 : | 3 | 2 | 1 |   a   q2 : |   |
                                                         p

pop()

q1 : | 3 | 2 | 1 |   --->   q1 : | 2 | 1 |



stack |   |
      | 2 |
      | 1 |


sol 2: push : o(1), pop : o(n)


push(3)

q1 : | 1 | 2 | --> q1: | 1 | 2 | 3 |


pop()
                                                           s
q1 : | 1 | 2 | 3 |   q1 : | 3 |           q1 : |  |        w   q1 : | 1 | 2 |
q2 : |   |           q2 : | 1 | 2 |       q2 : | 1 | 2 |   a   q2 : |   |
                                                           p 



*/


class MyStack {
public:

    queue<int> q;
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj- >push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */