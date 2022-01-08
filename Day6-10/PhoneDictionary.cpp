//link - https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#

/*Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory 
and a query string s. The task is to implement a search query for the phone directory. 
Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) 
that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".*/



// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
struct TrieNode{
    	unordered_map<char,TrieNode*> child;
    	bool isLast;
    	TrieNode(){
    		for (char i = 'a'; i <= 'z'; i++)
    			child[i] = NULL;
    		isLast = false;
    	}
    };
    TrieNode *root = NULL;
    
    void insert(string s){
    	int len = s.length();
    	TrieNode *itr = root;
    	for (int i = 0; i < len; i++){
    		TrieNode *nextNode = itr->child[s[i]];
    		if (nextNode == NULL){
    			nextNode = new TrieNode();
    			itr->child[s[i]] = nextNode;
    		}
    		itr = nextNode;
    		if (i == len - 1)
    			itr->isLast = true;
    	}
    }
    
    void insertIntoTrie(string s[],int n){
    	root = new TrieNode();
    	for (int i = 0; i < n; i++)
    		insert(s[i]);
    }
    
    
    void fill(TrieNode *cur,string pre, vector<string>&v){
        if(cur->isLast)v.push_back(pre);
        for(char c ='a';c<='z';c++){
            if(cur->child[c])fill(cur->child[c],pre+c,v);
        }
        
    }
    
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        insertIntoTrie(contact, n);
        TrieNode *prevNode = root;
        vector<vector<string>> res;
    	string prefix = "";
    	int len = s.length();
    	int i;
    	for (i = 0; i < len; i++){
    		vector<string> v;
    		prefix += s[i];
    		TrieNode * cur = prevNode->child[s[i]];
    		if(cur==NULL){
    		    v.push_back("0");res.push_back(v);
    		    i++;
    		    break;
    		}
    		prevNode = cur;
    		fill(cur,prefix,v);
    		res.push_back(v);
    	}
    	for (; i<len; i++){
    	    vector<string> v;
    	    v.push_back("0");
    	    res.push_back(v);
    	}
    	return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends