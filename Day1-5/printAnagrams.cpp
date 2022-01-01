//question link https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
//question -
//Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.





// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& stl) {
        int n=stl.size();
        map<string,vector<string>>mp;
        vector<string>v(n);
        vector<vector<string> > ans;
        map<string,int>hash;
        for(int i=0;i<n;i++)
        {
            string s= stl[i];
            sort(s.begin(),s.end());
            mp[s].push_back(stl[i]);
            v[i]=s;
            
        }
        for(int i=0;i<n;i++)
        {
            if(!hash[v[i]]){
                ans.push_back(mp[v[i]]);
                hash[v[i]]=1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends