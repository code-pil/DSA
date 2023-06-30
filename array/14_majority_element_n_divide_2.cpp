#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ct=0,ele;
	for(int i=0;i<n;i++){
		if(!ct) ele=arr[i];
		if(arr[i] == ele) ct++;
		else ct--;
	}
	int cnf=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ele) cnf++;
	}
	if(cnf>n/2) return ele;
	return -1;
} 
