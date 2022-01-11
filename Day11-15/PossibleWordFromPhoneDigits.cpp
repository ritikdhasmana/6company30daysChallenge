//link - https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#

/*Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], 
the task is to list all words which are possible by pressing these numbers.*/


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unordered_set<string>st;
    int *arr;
    int n;
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        arr = a;
        n=N;
        //Your code here
        vector<string> res;
        getwords(0,"",res);
        // vector<string>v(st.begin(),st.end());
        return res;
    }
    private :
    void getwords(int i,string curr, vector<string> &res) {
        if(i == n) {
            res.push_back(curr);
            return;
        }
        string s = key(arr[i]);
        for(int j=0; j<s.size(); j++)
            getwords(i+1,curr+s[j], res);
    }
    string key(int i){
        switch(i) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }
};



// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends