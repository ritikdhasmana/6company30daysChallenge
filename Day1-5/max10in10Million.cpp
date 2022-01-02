//Find max 10 numbers in a list having 10Million entries.



#include <bits/stdc++.h>
using namespace std;

 #define ll long long 
int main() {
	
	int T=1;
	// cin>>T;
	while(T--)
	{
		ll total = 1e7;
        vector<ll> entries(total);
        iota(entries.begin(), entries.end(),1); //filll array w 10 mil entries starting from 1;
        
        //queue to keep track of top 10 entries;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto e : entries){
            pq.push(e);
            if(pq.size()>10)pq.pop();
        }
        cout<<"Max 10 entries- ";
        while(pq.size()){
            cout<<pq.top()<<" ";
            pq.pop();
            
        }cout<<endl;
	}
	return 0;
}// } Driver Code Ends
