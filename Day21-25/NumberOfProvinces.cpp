
class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        vector<vector<int>>g(graph.size());
        int n = g.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(graph[i][j]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(!vis[i]){
                cnt++;
                dfs(i,g,vis);
            }
        return cnt;
    }
private :
    void dfs(int u, vector<vector<int>>&g, vector<int>&vis){
        vis[u]=true;
        for(auto v : g[u])
            if(!vis[v])dfs(v,g,vis);
        
    }
};



