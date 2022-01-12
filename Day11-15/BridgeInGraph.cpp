//link-https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

//question-
//Given a Graph of V vertices and E edges and another edge(c - d), 
//the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    // unordered_map<int,int>mp;
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        if(find(adj[c].begin(),adj[c].end(),d)!=adj[c].end())
            adj[c].erase(find(adj[c].begin(),adj[c].end(),d));
        if(find(adj[d].begin(),adj[d].end(),c)!=adj[d].end())
            adj[d].erase(find(adj[d].begin(),adj[d].end(),c));
            
        vector<bool> vis(V+1,false);
        dfs(d,adj,vis);
        return vis[c] ? 0 : 1;
    }
    void dfs(int u, vector<int> adj[],vector<bool>&vis){
        vis[u]=true;
        for(auto v : adj[u]){
            if(!vis[v])dfs(v,adj,vis);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends