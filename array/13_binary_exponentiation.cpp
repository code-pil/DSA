#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int ans = 1;
	while(n){
		if(n&1) ans = (ans*1LL*x)%m;
		x = (x*1LL*x)%m;
		n >>=1;
	}
	return ans;
}
