//link- https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
/*
question -
Given an integer array arr of size N, 
the task is to divide it into two sets S1 and S2 such that 
the absolute difference between their sums is minimum and find the minimum difference
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	   
	    bitset<1000001> dp = {1};
	    int tot=0;
	    for(int i=0;i<n;i++){
	        for(int s =sum/2;s>=arr[i];s--){
	            dp[s] = dp[s] || dp[s-arr[i]];
	        }
	    }
	    for(int i=sum/2;i>-1;i--){
	        if(dp[i])return sum - i-i;
	    }
	    return sum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends