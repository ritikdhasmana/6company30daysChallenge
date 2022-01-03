//link- https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#
//question -
//Given an array of integers and a number k, 
//write a function that returns true if given array can be divided into pairs 
//such that sum of every pair is divisible by k.



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int t[k+1];
        memset(t,0,sizeof(t));
        for(auto  n : nums)t[n%k]++;
        if(t[0]%2)return false;
        int i,j;
        for(i=1,j=k-1;i<j;i++,j--){
            if(t[i]!=t[j])return false;
        }
        if(i==j && t[i]%2)return false;
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends