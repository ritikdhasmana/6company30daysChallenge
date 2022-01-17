//link- https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

//Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.



// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<vector<string>> dp(n+1);
        dp[1].push_back("()");
        for(int i=2;i<=n;i++){
            set<string>st;
            for(int j=1;j<i;j++){
                for(string s1  : dp[j]){
                    for(string s2 : dp[i-j]){
                        st.insert(s1+s2);
                    }
                }
            }
            for(string s : dp[i-1])st.insert('('+s+')');
            dp[i] = vector<string>(st.begin(),st.end());
        }
        return dp[n];
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends