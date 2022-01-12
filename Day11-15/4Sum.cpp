//link- https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1


//question-
//Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> ans;
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        sort(nums.begin(), nums.end());
        kSum(nums, target, 4);
        return ans;
    }
    void kSum(vector<int>& nums, int target, int k) {
        vector<int> tmp;
        dfs(nums, 0, (int)nums.size() - 1, k, target, tmp);
    }
    void dfs(vector<int>& nums, int l, int r, int k, int target, vector<int>& path) {
        if (k == 2) {
            while(l<r){
                if(nums[l]+nums[r]==target){
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    ++l; --r;
                    while(l<r && nums[l]==nums[l-1])l++;
                    
                }else if(nums[l]+nums[r] > target)r--;
                else l++;
            }
        }else{
            while(l<r){
                path.push_back(nums[l]);
                dfs(nums,l+1,r,k-1,target-nums[l],path);
                path.pop_back();
                ++l;
                while(l<r && nums[l]==nums[l-1])l++;
            }
        }
            
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends