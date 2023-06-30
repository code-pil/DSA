//GFG : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

  public:
	int minDifference(int arr[], int n)  { 

		//code for subset sum possible of not for sum {0 , sumOfAllElementsOfArray}
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    int dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0) dp[i][j]=false;
	            if(j==0) dp[i][j]=true;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1] <= j) dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
	            else dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    vector<int> sums;

	    //finding that which sums are possible for s1
	    //if we find s1 so easily we can find s2 = sum-s1
	    for(int i=0;i<=sum;i++){
	        if(dp[n][i]) sums.push_back(i);
	    }
	    
	    int minDiff = INT_MAX;

	    /*
						N/2
		0 ..... s1 ..... | ....... s2 ...... sum
	
		s1 in left part less that n/2
		s2 in right part = sum - s1

		if s1 in right part 
		s2 will be in left part = sum - s1

		so just take value of s1 to middle

	    */
	    
	    for(int i=0;i<=sums.size()/2;i++){
	        int s1=sums[i];
	        // s2 = sum - s1
	        // abs(s2-s1) = abs(sum-2*s1)
	        minDiff = min(minDiff, abs(sum-2*s1));
	    }
	    
	    return minDiff;
	    
	} 
};


// space optimized

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<int> dp(sum+1, 0);
	    dp[0]=1;
	    
	    for(int i=0;i<n;i++){
	        for(int j=sum;j>=0;j--){
	            if(arr[i] <= j) dp[j] = dp[j-arr[i]] or dp[j];
	            else dp[j] = dp[j];
	        }
	    }
	    
	    vector<int> sums;
	    for(int i=0;i<=sum;i++){
	        if(dp[i]) sums.push_back(i);
	    }
	    
	    int minDiff = INT_MAX;
	    
	    for(int i=0;i<=sums.size()/2;i++){
	        int s1=sums[i];
	        // s2 = sum - s1
	        // abs(s2-s1) = abs(sum-2*s1)
	        minDiff = min(minDiff, abs(sum-2*s1));
	    }
	    
	    return minDiff;
	    
	} 
};