/*

Solution 1: store pair<int,int> of <ele, curMin>

Solution 2: 

Intiution

in push(val) if(val < mini)

    push--> 2*val-mini --> to retrive prevmini while pop

    cause val<mini
          val+val<val+mini
          2*val - mini < val

int pop if(st.top < mini)

    so we need to update mini 
    cause current mini = original MINI = val
    and in stack we pushed modified value 2*val-prevmini

    mini = 2*mini - ele
         = 2*val - (2*val - prevmini)
    mini = prevmini

*/



class MinStack {
    stack<long long int> st;
    long long int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                st.push(2LL*val-mini);
                mini = val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long int ele = st.top();
        st.pop();
        if(ele < mini){
            mini = 2LL*mini - ele;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long ele = st.top();
        if(ele < mini){
            return mini;
        }
        return ele;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */