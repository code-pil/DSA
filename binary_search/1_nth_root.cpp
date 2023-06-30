//General Version

#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}
int main() {
	int n=3, m=27; 
	getNthRoot(n, m); 
	return 0;
}


//coding ninjas version

int NthRoot(int n, int m) {
  int lo=1;
  int hi=m;
  int ans=-1;
  while(lo<=hi){,,,~
    int mid = (lo+hi)/2;
    long long int x = 1;

    for(int i=1;i<=n;i++){
      x*=mid;
      if(x > 1LL*m) break;
    }

    if(x==1LL*m) {
      ans=mid;
      break;
    }
    if(x<1LL*m) lo=mid+1;
    else hi=mid-1;
  }

  return ans;

}
