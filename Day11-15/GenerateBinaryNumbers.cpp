//link - https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#



/*
question -
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N. 
*/




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	queue<string> q;
	q.push("1");
	vector<string> ans;
	int cnt=0;
	while(q.size()){
	    string t = q.front();
	    q.pop();
	    ans.push_back(t);
	    cnt++;
	    if(cnt==N)return ans;
	    q.push(t +'0');
	    q.push(t+'1');
	    
	}
// 	vector<string> v (st.begin(),st.end());
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends