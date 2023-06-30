#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xxor=0;
	for(int i=0;i<n;i++) xxor^=arr[i],xxor^=(i+1);

	int set_bit = xxor & ~(xxor-1);
	int x=0,y=0;
	for(int i=0;i<n;i++){
		if(arr[i] & set_bit) x^=arr[i];
		else y^=arr[i];

		if((i+1) & set_bit) x^=(i+1);
		else y^=(i+1);
	}
	int x_count = 0;
	for(auto ele : arr) if(ele==x) x_count++;
	if(x_count) return {y,x};
	return {x,y};
}

