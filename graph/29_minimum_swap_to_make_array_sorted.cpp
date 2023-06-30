//GFG: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++){
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    int ans = 0;
	    bool vis[n] = {false};
	    for(int i=0;i<n;i++){
	        if(vis[i] == true or v[i].second == i) continue;
	        int clen = 0;
	        int j = i;
	        while(vis[j] == false){
	            vis[j] = true;
	            clen++;
	            j = v[j].second;
	        }
	        ans += clen -1;
	    }
	    return ans;
	    
	}
};