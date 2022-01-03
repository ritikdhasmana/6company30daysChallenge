//link- https://practice.geeksforgeeks.org/problems/decode-the-string2444/1#

//question-
//An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
// original string: abbbababbbababbbab 
// encoded string : 3[a3[b]1[ab]]




// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        int i=0;
        return decode(s,i);
    }
private :

    
    string decode(string s, int &ind){
        string res = "";
        while(ind<s.length() && s[ind]!=']'){
            if(!isdigit(s[ind])){
                res += s[ind++];
            }
            else{
                int num=0;
                while(ind<s.length() && isdigit(s[ind])){
                    num =num*10 + (s[ind]-'0');
                    ind++;
                }
                ind++;
                string t = decode(s,ind);
                ind++;
                while(num--)res += t;
            }
        }return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends