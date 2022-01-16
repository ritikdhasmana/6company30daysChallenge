//link - https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

/*
question -
Given an array arr[] of size N, check if it can be partitioned into two parts 
such that the sum of elements in both parts is the same.
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)sum += arr[i];
        if(sum%2)return 0;
        int dp[sum/2 +1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            for(int j=sum/2;j>=arr[i];j--){
                dp[j] =dp[j]||dp[j-arr[i]];
            }
        }
        return dp[sum/2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends