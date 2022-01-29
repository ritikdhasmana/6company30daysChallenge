class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<vector<int>> w;
        for(int i=0;i<n;i++){
            w.push_back({s[i],e[i]});
        }
        sort(begin(w),end(w),[](auto &a, auto &b){
            return a[1]>b[1];
        });
        long ans=0;
        long tot=0, minef=0;
        for(int i=0;i<k;i++){
            tot += w[i][0];
            minef=w[i][1];
            pq.push(w[i][0]);
            ans = max(ans,tot*minef);
        }
        for(int i=k;i<n;i++){
            if(w[i][0]<=pq.top())continue;
            tot += w[i][0] - pq.top();
            pq.pop();
            pq.push(w[i][0]);
            minef=w[i][1];
            ans = max(ans,tot*minef);
        }
        return ans%1000000007;
    }
};