//link - https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/#

/*
question -
Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int n,m;
    int find(int A[], int B[], int i, int j){
        if(j==m)return 0;
        if(i==n)return INT_MAX;
        int ans=INT_MAX;
        if(A[i]==B[j])ans = find(A,B,i+1,j+1);
        ans = min(ans,find(A,B,i+1,j)+1);
        ans = min(ans, find(A,B,i,j+1)+1);
        return ans;
    }
    int lis(vector<int>v){
        vector<int>res;
        for(int i=0;i<v.size();i++){
            auto it = lower_bound(res.begin(),res.end(),v[i]);
            if(it==res.end())res.push_back(v[i]);
            else{
                *it = v[i];
            }
        }
        return res.size();
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        n=N;
        m=M;
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i=0;i<m;i++)mp[B[i]]++;
        for(int i=0;i<n;i++){
            if(mp.count(A[i]))v.push_back(A[i]);
        }
        return n+m - 2*lis(v);
        // int dp[n+1][m+1];
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         if(i==0)dp[i][j]=j;
        //         else if(j==0)dp[i][j]=i;
        //         else if(A[i-1]==B[j-1]){
        //             dp[i][j]=dp[i-1][j-1];
        //         }else{
        //             dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m];
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends