//link - https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#


/*
question -
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 
*/




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        g.resize(n,vector<int>(m));
        g=grid;
        n= g.size(),m=g[0].size();
        ans =0;
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int dis=0;
                if(!vis[i][j] && g[i][j])dfs(i,j,dis,vis);
            }
        }
        return ans;
    }
    private : 
    vector<vector<int>>g;
    int n, m;
    int ans;
    void dfs(int i, int j, int &dis,vector<vector<bool>>&vis){
        if(i>=n || j>=m||i<0 ||j<0 || g[i][j]!=1 || vis[i][j])return;
        
        vis[i][j]=true;
        dis++;
        ans = max(ans, dis);
        for(int r = i-1;r<i+2;r++){
            for(int c = j-1;c<j+2;c++){
                dfs(r,c,dis,vis);
            }
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends