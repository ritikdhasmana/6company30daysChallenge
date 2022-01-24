class Solution {
public:
    bool check(int m, vector<int>&piles, int h){
        int hrs=0;
        for(auto p : piles){
            hrs += ceil(double(p)/m);
        }
        // cout<<hrs<<" "<< h<<" "<< (hrs<=h) << endl;
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r= *max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid = (r-l)/2 + l;
            if(check(mid,piles,h)){
                // cout<<mid<<" "<<h<<endl;
                r=mid-1;
            }else l=mid+1;
        }return l;
    }
};
