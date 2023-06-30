class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int> a[n+1];
        for(int i=0;i<n;i++){
            a[i].first = end[i];
            a[i].second = i;
        }
        
        sort(a, a+n);
        
        int limit = a[0].first;
        vector<int> ans;
        ans.push_back(a[0].second+1);
        
        for(int i=1;i<n;i++){
            if(start[a[i].second] > limit){
                ans.push_back(a[i].second + 1);
                limit = a[i].first;
            }
        }
        
        return ans.size();
        
    }
};
