//link - https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/#

/*
question -
Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. 
If more than one such range's are found, return the first such range found.
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
typedef pair<int, pair<int, int>> pi;
class Solution{
    public:
    pair<int,int> findSmallestRange(int nums[][N], int m, int k)
    {
        int n = k;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],{i,0}});
            mn = min(mn,nums[i][0]);
            mx = max(mx,nums[i][0]);
        }
        int a = mn, b = mx;
        while(pq.size()>=n){
            auto it = pq.top();
            pq.pop();
            if(it.second.second < m-1){
                int r = it.second.first, c = it.second.second +1;
                pq.push({nums[r][c],{r,c}});
                mn = pq.top().first;
                mx = max(mx, nums[r][c]);
                if(b-a > mx -mn){
                    b=mx;
                    a=mn;
                }
            }else{
                break;
            }
        }
        return {a,b};
          //code here
        //   pair<int,int>ans;
        //   ans.first=-1;
        //   ans.second =-1;
        //   if(k==1){
        //       return {a[0][0],a[0][0]};
        //   }
        //   int d = INT_MAX;
        //   multiset<tuple<int,int,int>>mp;
        //   for(int i=0;i<k;i++)mp.insert(make_tuple(a[i][0],i,0));
        //   while(mp.size()==k){
        //       auto t1 = *(mp.begin()), t2 = *(mp.rbegin());
        //       mp.erase(mp.begin());
        //       int v1 = get<0>(t1), v2 = get<0>(t2);
        //       int r1 = get<1>(t1), r2 = get<1>(t2);
        //       int c1 = get<2>(t1), c2 = get<2>(t2);
        //       if(d>v2-v1){
        //           d=v2-v1;
        //           ans.first = v1;
        //           ans.second = v2;
        //       }
        //       c1++;
        //       if(c1<n){
        //           mp.insert(make_tuple(a[r1][c1],r1,c1));
        //       }
        //   }
        //   return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends