
//link - https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

/*
question -
Given two numbers n and x, find out the total number of ways n can be expressed as sum of xth power of unique natural numbers.

*/
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int numOfWays(int n, int x)
    {
        // code here
        // vector<int>num;
        // int i=1;
        // while(pow(i,x)<=n)num.push_back(pow((i++),x));
        long long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(long long int i=2;pow(i,x)<=n;i++){
            int t = pow(i,x);
            for(long long int j = n;j>=t;j--){
                dp[j] += dp[j-t];
            }
        }
        return dp[n];
        // return ways(num,n);
    }
    private : 
    int ways(vector<int>&nums, int n, int ind=0){
        if(n==0)return 1;
        if(n<0||ind==nums.size())return 0;
        int ans=ways(nums,n,ind+1);
        if(nums[ind]<=n)ans += ways(nums,n-nums[ind],ind+1);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends