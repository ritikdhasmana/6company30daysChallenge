//link- https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/

/*
question-

Given a string consisting of some numbers, not separated by any separator. The numbers are positive integers and the sequence increases by one at each number except the missing number.
The task is to complete the function missingNumber which return's the missing number. The numbers will have no more than six digits. Print -1 if input sequence is not valid.
Note: Its is guaranteed that if the string is valid, then it is sure that atleast one number would be missing from the string.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int missingNumber(const string& str)
{
    // Code here
    int n= str.size();
    for(int len=1;len<=6;len++){
        string temp="";
        long long ans=-1;
        int i=0;
        while(i<str.length()&& i<len)temp.push_back(str[i++]);
        if(!isNumber(temp))return -1;
        long long num = stoll(temp);
        long long int j=i,f=0,cnt=0;
        temp = "";
        while(j<str.size()){
            temp += str[j++];
            if(num+1 == stoll(temp)){
                num=num+1;
                temp="";
            }else if(num+2==stoll(temp)){
                cnt++;
                ans =  1+num;
                num = num+2;
                temp="";
            }else if(num<stoll(temp)){
                f=1;
                break;
            }
        }
        if(!f && cnt==1)return ans;
    }
    return -1;
}
