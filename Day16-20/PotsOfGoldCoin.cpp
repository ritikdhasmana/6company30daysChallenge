 
 //link - https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/

/*
question -

Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. 
They get alternating turns in which the player can pick a pot from one of the ends of the line. 
The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.
Return the maximum coins X could get while playing the game. Initially, X starts the game.

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&piles,int n)
    {
	    //Write your code here
	    int sum=0;
        for(auto i : piles)sum+=i;
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        // for(int i=1;i<=n;i++)dp[i][i] = piles[i-1];
        for(int i=n-1;i>-1;i--){
            for(int j=i;j<n;j++){
                if(i>j)continue;
                if(i==j){
                    dp[i][j] =piles[i];
                }else if(i==j-1){
                    dp[i][j] = max(piles[i],piles[j]);
                }else{
                    dp[i][j] = max(piles[i] + min(dp[i+2][j] , dp[i+1][j-1]),
                                   piles[j] + min(dp[i+1][j-1] , dp[i][j-2]));
                }
            }
        }
        // cout<<dp[0][n-1]<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        // cout<<sum/2 <<" "<<dp[0][n-1]<<endl;
        return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends