//link- https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#

//question-
/*Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. 
Find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. 
There are many options to multiply a chain of matrices 
because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        return find(p,0,n-1).second;
    }
private :
    map<string,pair<int,string>>mp;
    pair<int,string>find(int p[],int st, int e){
        if(st+1==e){
            return {0,string(1,'A'+st)};
        }
        string key = to_string(st) + '#' + to_string(e);
        if(mp.count(key))return mp[key];
        string minstring;
        int curmin =INT_MAX;
        for(int k=st+1;k<e;k++){
            auto l = find(p,st,k), r = find(p,k,e);
            if(curmin> l.first + r.first + p[st]*p[k]*p[e]){
               curmin= l.first + r.first + p[st]*p[k]*p[e] ;
               minstring = "(" + l.second + r.second + ")";
            }
        }
        return mp[key] = {curmin, minstring};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends