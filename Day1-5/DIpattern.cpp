//linnk- https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

//question- 
/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

 
*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        memset(mp,0,sizeof(mp));
        ans="999999999";
        for(int i=1;i<10;i++){
            mp[i]=1;
            findpattern(S,0,to_string(i));
            mp[i]=0;
        }
        return ans;
    }
private :
    int mp[10];
    string ans;
    void findpattern(string s, int ind, string cur){
        if(ind == s.length()){
            ans = min(ans,cur);
            return ;
        }
        for(int i=1;i<10;i++){
            if(mp[i]==1)continue;
            mp[i]=1;
            // cout<<cur<<" "<<i<<" "<<ind<<endl;
            if(s[ind]=='D'){
                if(cur[cur.size()-1]-'0'>i){
                    cur.push_back(i+'0');
                    
                    findpattern(s,ind+1,cur);
                    cur.pop_back();
                    
                }
            }else{
                if(cur[cur.size()-1]-'0'<i){
                    cur.push_back(i+'0');
                    
                    findpattern(s,ind+1,cur);
                    cur.pop_back();
                    
                }
            }
            mp[i]=0;
        }
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends