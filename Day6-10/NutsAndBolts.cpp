//link- https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1


//question- 
// Given a set of N nuts of different sizes and N bolts of different sizes. 
//There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.
//Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
//It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
//The elements should follow the following order ! # $ % & * @ ^ ~ .


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    vector<char> v(9,'1');
	    for(int i=0;i<n;i++){
	        if(nuts[i]=='!')v[0]='!';
            else if(nuts[i]=='#')v[1]='#';
            else if(nuts[i]=='$')v[2]='$';
            else  if(nuts[i]=='%')v[3]='%';
            else if(nuts[i]=='&')v[4]='&';
            else if(nuts[i]=='*')v[5]='*';
            else if(nuts[i]=='@')v[6]='@';
            else if(nuts[i]=='^')v[7]='^';
            else v[8]='~';
	    }
	    int j=0;
	    for(int i=0;i<9;i++){
	        if(v[i]!='1'){
	            nuts[j]=v[i];
	            bolts[j]=v[i];
	            j++;
	        }
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends