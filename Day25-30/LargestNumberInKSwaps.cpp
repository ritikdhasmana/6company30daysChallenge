#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void swaps(string str,int k,string &res,string &ans,int ind)
    {
        if(k==0)return;
        for(int i=ind;i<str.length();i++)
        {
            for(int j=i+1;j<str.length();j++)
            {
                if(str[i]<str[j]){
                    swap(str[i],str[j]);
                    if(str.compare(ans)>0)ans=str;
                    swaps(str,k-1,res,ans,i+1);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string res="",ans=str;
       swaps(str,k,res,ans,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends