//link - https://www.geeksforgeeks.org/adobe-interview-experience-for-mts-1-1-5-years-experienced/

/*
question -
Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”.
 Find out which one is more recent? Strings can be empty also.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]>b[i])cout<<a<<endl;
            else if(b[i]>a[i])cout<<b<<endl;
            if(a[i]!=b[i])break;
        }
        
    }
	return 0;
}  // } Driver Code Ends