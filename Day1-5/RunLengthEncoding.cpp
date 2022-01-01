//link -https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

//Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
//eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
//You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string s ="";
  int cnt=1;
  for(int i=1;i<src.length();i++){
      if(src[i]==src[i-1])cnt++;
      else{
          s += src[i-1] + to_string(cnt);
          cnt=1;
      }
  }
  s += src[src.length()-1] + to_string(cnt);
  return s;
}     
 
