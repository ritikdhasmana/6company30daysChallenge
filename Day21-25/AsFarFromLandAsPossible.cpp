class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        unordered_map<int,int>mp;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]){
                    q.push({i,j});
                    g[i][j]=0;
                }
            }
        }
        int ans=-1;
        int dis=0;
        while(q.size()){
            int n= q.size();
            while(n--){
             int i= q.front().first, j = q.front().second;q.pop();
                if(i>=0 && j>=0 && i<g.size() && j<g[0].size() && g[i][j]==0){
                    g[i][j]=dis+1;
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i+1,j});
                    q.push({i,j-1});
                }
            }dis++;
        }
        
        return dis<=2 ? -1 :(dis-2);
    }
};

