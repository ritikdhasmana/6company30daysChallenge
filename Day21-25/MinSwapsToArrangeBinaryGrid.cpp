class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
//         sort(grid.begin(),grid.end(),[&](auto &a, auto &b){
//            int cnta=0,cntb=0;
//             for(int i=a.size()-1;i>-1;i--){
//                 if(a[i]==1)break;
//                 cnta++;
//             }
//             for(int i=a.size()-1;i>-1;i--){
//                 if(b[i]==1)break;
//                 cntb++;
//             }
//             return cnta > cntb;
            
//         });
        int n = grid.size(),cnt=0;
        vector<int> rzero(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            int j=n-1;
            while(j>-1 && grid[i][j]==0)j--;
            rzero[i] = n - j-1;
        }
        for(int i=0;i<n;i++){
            int req = n-i-1;
            cout<<req<<" "<<rzero[i]<<endl;
            if(rzero[i]>=req)continue;
            int j=i+1;
            while(j<n && rzero[j]<req){
                j++;
            }
            if(j==n)return -1;
            cnt += j-i;
            while(j>i){rzero[j]=rzero[j-1];j--;}
        }
        return cnt;
    }
};
