//. Find the kid which gets tha damaged toy
//link - https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1#

//question- 
//M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.


// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int n , int m, int k) {
        // code here
        if(n==1)return 1;
        int newp = (m-1)%n;
        newp = (newp+k)%n;
        return newp==0 ? n : newp;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends