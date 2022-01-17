//link- https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/


// Given a palindromic number N in the form of string. The task is to find the smallest palindromic number greater than N using the same set of digits as in N.



// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string n) { 
        //complete the function here
        int ind=0;
        if(n.size()<=3)return "-1";
        string res = n.substr(0,n.length()/2);
        if(next_permutation(res.begin(),res.end())){
            string ans = res;
            if(n.size()%2)ans.push_back(n[n.size()/2]);
            reverse(res.begin(),res.end());
            ans += res;
            return ans;
        }
        return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends