class Solution {
public:
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return find(1,n);
    }
private :
    int dp[201][201];
    int find(int l, int r){
        if(l>=r)return 0;
        if(dp[l][r]==-1){
            dp[l][r]= INT_MAX;
            for(int i=l;i<r+1;i++){
                dp[l][r] = min(dp[l][r], i+max(find(i+1,r),find(l,i-1)));
            }
        }
        return dp[l][r];
    }
};