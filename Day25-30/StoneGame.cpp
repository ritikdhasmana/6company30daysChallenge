bool stoneGame(vector<int>& piles) {
        return true;
        
        
        
        
        
        
        
        
        
        // int sum = 0;
        // for(auto i : piles)sum+=i;
        // // int x = check(piles,0,piles.size()-1);
        // int  n = piles.size();
        // int dp[n+1][n+1];
        // memset(dp,0,sizeof(dp));
        // dp[0][0]=0;
        // // for(int i=1;i<=n;i++)dp[i][i] = piles[i-1];
        // for(int i=n-1;i>-1;i--){
        //     for(int j=i;j<n;j++){
        //         if(i>j)continue;
        //         if(i==j){
        //             dp[i][j] =piles[i];
        //         }else if(i==j-1){
        //             dp[i][j] = max(piles[i],piles[j]);
        //         }else{
        //             dp[i][j] = max(piles[i] + min(dp[i+2][j] , dp[i+1][j-1]),
        //                            piles[j] + min(dp[i+1][j-1] , dp[i][j-2]));
        //         }
        //     }
        // }
        // // cout<<dp[0][n-1]<<endl;
        // // for(int i=0;i<n;i++){
        // //     for(int j=0;j<n;j++){
        // //         cout<<dp[i][j]<<" ";
        // //     }cout<<endl;
        // // }
        // return dp[0][n-1] > sum/2;
    }