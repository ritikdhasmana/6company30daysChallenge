
//link- https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

//question-
//Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int sum=0;
        vector<int>ans;
        deque<int>dq;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
            while(dq.size() && dq.back()<=arr[i])dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());
        for(int i=k;i<n;i++){
            mp[arr[i-k]]--;mp[arr[i]]++;
            while(dq.size() && dq.back()<=arr[i])dq.pop_back();
            while(dq.size() && mp[dq.front()]==0)dq.pop_front();
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends