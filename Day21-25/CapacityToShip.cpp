
class Solution {
public:
    int shipWithinDays(vector<int>& wt, int days) {
        int l = 0,h = 25000000;
        for (int w: wt)
            l = max(l, w);
        while(l<h){
            int mid = l + (h-l)/2;
            if(check(wt,mid,days)){
                h = mid;
            }else{
                l=mid+1;
            }
        }return l;
    }
private : 
    bool check(vector<int>&wt, int x, int d){
        int cnt=1,cur=0;
        for(int w :wt){
            if(cur+w>x){
                cur=0;
                cnt++;
            }
            cur +=w;
        }
        return cnt <=d;
    }
};

