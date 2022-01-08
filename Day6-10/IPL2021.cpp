//link - https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

//question-
/*
Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.
Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. 
Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab.
He has stats of runs scored by all N players in the previous season and 
he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.
 */


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        // if(k>=n)return accumulate(arr.begin(),arr.end(),0);
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

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
