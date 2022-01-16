//link - https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

/*
question -
Given an array called A[] of sorted integers having no duplicates, 
find the length of the Longest Arithmetic Progression (LLAP) in it.

*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int nums[], int n) {
        vector<vector<int>>dp(n,vector<int>(nums[n-1]-nums[0]+2,0));
        int ans =1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dif = nums[j] - nums[i] ;
                dp[j][dif] = max(2,dp[i][dif]+1);
                ans = max(ans,dp[j][dif]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends