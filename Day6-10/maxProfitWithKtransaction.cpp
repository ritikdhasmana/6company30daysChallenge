//link https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

//question -
//In the stock market, a person buys a stock and sells it on some future date.
// Given the stock prices of N days in an array A[ ] and a positive integer K,
 //find out the maximum profit a person can make in at-most K transactions. 
 //A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.



// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        if(k>=n/2){
            int res=0;
            for (int i = 1; i < n; ++i) res += max(0, prices[i] - prices[i - 1]);
            return res;
        }
        if(k==0)return 0;
        vector<int> buy(k+1,INT_MIN),sell(k+1,0);
        for(int j=0;j<n;j++){
            int p = prices[j];
            for(int i=0;i<k;i++){
                buy[i] = max(buy[i],(i>0 ? sell[i-1] : 0) - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }return sell[k-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends