//link-https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

/*
question-

Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
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
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
    string res="",ans=str;
       swaps(str,k,res,ans,0);
       return ans;
       // code here.
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
