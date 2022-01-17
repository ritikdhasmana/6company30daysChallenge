//link- https://practice.geeksforgeeks.org/problems/implement-atoi/1/

/*
question -
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0;
        int i = (str[0]=='-' ? 1 : 0);
        for(;i<str.length();i++){
            if(isdigit(str[i])){
                ans = ans*10 + (str[i]-'0');
            }else return -1;
        }
        if(str[0]=='-')ans = 0-ans;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends