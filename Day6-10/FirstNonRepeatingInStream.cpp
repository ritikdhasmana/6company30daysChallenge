//link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// question - 
//Given an input stream of A of n characters consisting only of lower case alphabets.
// The task is to find the first non repeating character, each time a character is inserted to the stream.
// If there is no such character then append '#' to the answer.
 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    deque<int> dq;
		    string ans = "";
		    int f[256] ={0};
		    for(auto c : A){
		        f[c]++;
		        if(f[c]==1)dq.push_back(c);
		        while(dq.size()&&f[dq.front()]>1)dq.pop_front();
		        if(dq.size())ans.push_back(dq.front());
		        else ans.push_back('#');
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends