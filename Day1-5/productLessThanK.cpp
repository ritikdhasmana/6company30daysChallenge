//link - https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

//question-
//Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int product =1;
        int cnt=0,j=0;
        for(int i=0;i<n;i++){
            product *=a[i];
            while(j<n && product >= k){
                product/=a[j++];
            }
            cnt += i-j+1;
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends