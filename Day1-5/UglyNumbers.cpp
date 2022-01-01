//link-  https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#




// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
        dp[0] =1;
        // dp[1] =1;
        if(n<=5)return n;
        ull t=0, th=0, f=0;
        // dp[3]=3; dp[4]=4; dp[5]=5;
        for(int i=1;i<n;i++){
            dp[i] = min(2*dp[t],min(3*dp[th],5*dp[f]));
            if(dp[i]==2*dp[t])t++;
            if(dp[i]==3*dp[th])th++;
            if(dp[i]==5*dp[f])f++;
            // cout<<dp[i]<<endl;
        }
        return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends