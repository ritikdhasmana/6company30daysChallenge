//link - https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1#

/*
question -
Given a string which is basically a sentence without spaces between words. However the first letter of every word is in uppercase. 
You need to print this sentence after following amendments:
(i) Put a single space between these words
(ii) Convert the uppercase letters to lowercase.
Note: The first character of the string can be both uppercase/lowercase.
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans="";
        for(auto c : s){
            if(isupper(c) && ans!=""){
                ans.push_back(' ');
                
            }ans.push_back(tolower(c));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends