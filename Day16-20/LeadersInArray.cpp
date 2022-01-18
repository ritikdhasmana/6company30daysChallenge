//link - https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#

/*
question -
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader 
if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 

*/
// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>v;
        for(int i=0;i<n;i++){
            while(v.size() && v.back()<a[i])v.pop_back();
            if(v.size()==0 || v.back()>=a[i])v.push_back(a[i]);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends