//link-  https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#


//questions - 
//Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) 
//the task to check if the current configuration is valid or not where a 0 represents an empty block.
//Note: Current valid configuration does not ensure validity of the final solved sudoku. 

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int row[9][9]={0},col[9][9]={0},box[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0)continue;
                int c = mat[i][j]-1;
                int b = (i/3)*3 + j/3;
                if(row[i][c])return 0;
                if(col[j][c])return 0;
                if(box[b][c])return 0;
                
                row[i][c]=1;
                col[j][c]=1;
                box[b][c]=1;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends