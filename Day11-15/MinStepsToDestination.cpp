//link- https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/#

//question-
//Given an infinite number line. You start at 0 and can go either to the left or to the right.
//The condition is that in the ith move, youmust take i steps. Given a destination D , find the minimum number of steps required to reach that destination.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int minSteps(int D){
        // code here
        for(int i=1;i<10005;i++){
            int totforward = i*(i+1)/2;
            if(totforward<D)continue;
            else if(totforward==D)return i;
            else if((totforward-D)%2==0)return i;
        }
        return 0;
    }
// private :
//      int des;
//      int m=20000;
//      int findmin(int cur, int steps){
//          if(cur>m  || cur<m || steps>m)return INT_MAX;
//          if(cur==des)return 0;
//          return 1+ min(findmin(cur-steps,steps+1),findmin(cur+steps,steps+1));
//      }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends