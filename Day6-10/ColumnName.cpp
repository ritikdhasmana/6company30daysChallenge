//link - https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#

//question - 
/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, 
column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.*/



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here]
        string s = "";
        while(n){
            n--;
            int t = n%26;
            s.push_back(t + 'A');
            n =n/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends