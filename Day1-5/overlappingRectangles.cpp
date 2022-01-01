//link https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/#

//question-
//Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).
//Note: It may be assumed that the rectangles are parallel to the coordinate axis.


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // code here
    // if (l1[0] == r1[0] || l1[1] == r1[1] || l2[0] == r2[0]|| l2[1] == r2[1]) {
    //     return false;
    // }
    if (l1[0] >r2[0] || l2[0] > r1[0]||r1[1]> l2[1] || r2[1] > l1[1])
        return false;
 
    return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends