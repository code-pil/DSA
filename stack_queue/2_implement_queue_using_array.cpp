#include <bits/stdc++.h> 
class Queue {
    int f,r,size,maxSize;
    int *q;
public:
    Queue() {
        // Implement the Constructor
        f=0,r=0,size=0;
        q = new int[100001];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(f==r) return 1;
        return 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q[r]=data;
        r++;
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int ans = q[f];
        f++;
        size--;
        if(f==r) f=0,r=0;

        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;

        return q[f];
    }
};