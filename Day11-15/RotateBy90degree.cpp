//link - https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/


/*
question -
Given a square matrix[][] of size N x N. 
The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.
*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& a)
{
    int N = a.size();
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N/2;j++){
            swap(a[i][j],a[i][N-j-1]);
        }
    }
    for (i = 0; i < N; i++)
        for (j = i+1; j < N; j++)
           swap(a[i][j],a[j][i]);
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends