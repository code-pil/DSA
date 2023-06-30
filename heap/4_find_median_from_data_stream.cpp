/*


The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.



*/

// Two Heap Approach

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num) {
        if(maxHeap.size()==0 || maxHeap.top() >= num){
            maxHeap.push(num);
        }
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((minHeap.size()+maxHeap.size())&1) return maxHeap.top();
        return 0.5 * (maxHeap.top()+minHeap.top());
    }
};



// pbds ordered set

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

class MedianFinder {
public:

    ordered_set s;
    int n;

    MedianFinder(){
        n=0;
    }
    
    void addNum(int num) {
        s.insert({num,n++});
    }
    
    double findMedian() {
        if(n&1){
            return (*s.find_by_order(n/2)).first;
        }
        return 0.5 * (((*s.find_by_order(n/2)).first)+((*s.find_by_order(n/2-1)).first));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */