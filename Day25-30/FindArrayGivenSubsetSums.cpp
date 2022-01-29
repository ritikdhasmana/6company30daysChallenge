class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
          vector<int> ans;
        sort(begin(sums),end(sums));
        while(sums.size()>1){
            vector<int> l,r;
            int v = sums[1]-sums[0], lz=0;
            for(int i=0,j=0;i<sums.size();i++){
                if(sums[i]!=INT_MIN){
                    lz = sums[i]==0;
                    l.push_back(sums[i]);
                    r.push_back(sums[i]+v);
                    for(j = max(j+1,i+1);sums[j]!=sums[i]+v;j++);
                    sums[j]=INT_MIN;
                }
                
            }
            ans.push_back(v*(lz ? 1 : -1));
            sums = (lz ? l : r);
        }
        return ans;
    }
};