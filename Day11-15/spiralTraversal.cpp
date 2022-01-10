//link - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/


/*
question -

Given a matrix of size r*c. Traverse the matrix in spiral form.

*/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        int l=0,k=0,n=c,m=r,i;
        vector<int> ans;
        while(l<n&&k<m){
            for(i=l;i<n;i++){
                ans.push_back(mat[k][i]);
            }
            k++;
            for(i=k;i<m;i++)ans.push_back(mat[i][n-1]);
            n--;
            if(k<m){
                for(i=n-1;i>=l;i--)ans.push_back(mat[m-1][i]);
                m--;
            }
            if(l<n){
                for(i=m-1;i>=k;i--)ans.push_back(mat[i][l]);
                l++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends