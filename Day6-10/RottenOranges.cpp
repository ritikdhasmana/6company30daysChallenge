//link- https://leetcode.com/problems/rotting-oranges/submissions/

//question -
/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir={-1,0,1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)fresh++;
                else if(grid[i][j]==2)q.push({i,j});
            }
        int ans=-1;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int x = p.first + dir[d], y = p.second + dir[d+1];
                    if(x<m && x>=0 && y<n && y>=0 && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0)return -1;
        return ans ==-1 ? 0 : ans;
        
        
    }
};