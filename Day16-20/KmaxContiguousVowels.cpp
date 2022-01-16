//link - https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/#

/*
question -
Find the number of unique words consisting of lowercase alphabets only of length N 
that can be formed with at-most K contiguous vowels. 
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    int mod=1000000007;
    int kvowelwords(int n, int k) {
        // Write Your Code here
        K=k;
        memset(dp,-1,sizeof(dp));
        return find(n,k);
    }
    private :
    int K;
    int dp[1005][1005];
    int find(int n, int k){
        if(n==0)return 1;
        if(k<0)return 0;
        
        if(dp[n][k]==-1){
            int ans=0;
            for(char c ='a' ; c<='z';c++){
                if(isvow(c)){
                    if(k!=0)ans = (ans%mod + find(n-1,k-1)%mod)%mod;
                }else{
                    ans = (ans%mod + find(n-1,K)%mod)%mod;
                }
            }
            dp[n][k] = ans;
        }
        return dp[n][k];
    }
    int isvow(char c){
        return c=='a' || c=='i' || c=='e' || c=='o'||c =='u';
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends