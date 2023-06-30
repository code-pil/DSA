/*

Given an integer array nums and an integer k, return the k most frequent elements.
 You may return the answer in any order.


Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


solution 1:

priority Q solution in which we first find frequency of all elements of array store it in map 
and then push it into priotiry queue where key is frequency pair<int,int>

solution 2:

Quick select algorithm same as kth element in array here comparing elements are frequency of 
elements;


*/

// Priority Queue


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        for(auto ele : nums) mp[ele]++;

        for(auto [x,y] : mp){
            q.push({y,x});
            if(q.size() > k) q.pop();
        }

        vector<int> ans;

        while(k--) ans.push_back(q.top().second), q.pop();

        return ans;
    }
};



// Quick select

class Solution {
public:

    int partition(vector<pair<int,int>> &v, int lo, int hi){
        int pivot=v[lo].second;
        int left = lo+1;
        int right = hi;

        while(left <= right){
            if(v[left].second<pivot && pivot < v[right].second){
                swap(v[left],v[right]);
                left++,right--;
            }

            if(v[left].second >= pivot) left++;
            if(v[right].second <= pivot) right--;
        }
        swap(v[lo],v[right]);

        return right;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        map<int,int> m;
        for(auto ele : nums) m[ele]++;

        for(auto [x,y] : m){
            v.push_back({x,y});
        }

        int lo=0,hi=v.size()-1;
        vector<int> ans;

        while(1){
            int pivot = partition(v, lo, hi);

            if(pivot == k-1){
                for(int i=0;i<k;i++){
                    ans.push_back(v[i].first);
                }
                return ans;
            }

            if(pivot >= k-1) hi=pivot-1;
            else lo=pivot+1;
        }

        return ans;
    }
};