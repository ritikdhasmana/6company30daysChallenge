
//find the total number of squares in n*n chess board;


//observation -
// 1^2 + 2^2 + 3^2 + ... + n^2 = n(n+1)(2n+1) / 6 



#include <bits/stdc++.h>
using namespace std;

int count(int n){
    return (n * (n + 1) / 2) * (2 * n + 1) / 3;
}
 
int main() {
	
	int T=1;
	// cin>>T;
	while(T--)
	{
		int n;
        cout<<"Enter n- "<<endl;
		cin>>n;
		
		cout<<count(n)<<endl;
	}
	return 0;
}// } Driver Code Ends

