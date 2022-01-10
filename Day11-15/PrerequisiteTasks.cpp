//link - https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/


/*
question -
There are a total of N tasks, labeled from 0 to N-1. 
Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> indeg(N,0);
	    vector<vector<int>>mp(N);
	    for( auto p : pre){
	        indeg[p.first] ++;
	        mp[p.second].push_back(p.first);
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            indeg[i]==-1;
	            q.push(i);
	        }
	    }
	    while(q.size()){
	        int u = q.front();
	        q.pop();
	        for(auto v : mp[u]){
	            if(indeg[v]==-1)continue;
	            indeg[v]--;
	            if(indeg[v]==0){
	                indeg[v]=-1;
	                q.push(v);
	            }
	        }
	    }
	    for(int i=0;i<N;i++)if(indeg[i]>0)return false;
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends