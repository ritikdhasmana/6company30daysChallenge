//link- https://practice.geeksforgeeks.org/problems/burning-tree/1/

/*question - 
Given a binary tree and a node called target. 
Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. 
That is its left child, right child, and parent.

*/



// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++
//create child to parent connection do bfs or dfs

class Solution {
  public:
  int res = 0;
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int h=0;
        burnTree(root,target);
        return res;
    }
    private :
    int burnTree(Node *root, int t ){
        if(!root)return -1;
        if(root->data==t){
            burnchild(root,NULL,0);
            return 1; // we return time taken for fire to reach root  + 1; -1 in case there isnt fire in subtree;
        }
        int left = burnTree(root->left, t);
        if(left!=-1){
            burnchild(root,root->left,left);
            return left + 1;
        }
        int right= burnTree(root->right,t);
        if(right!=-1){
            burnchild(root,root->right, right);
            return right + 1;
        }
        return -1;
    }
    void burnchild(Node *root, Node *already_burnt, int curtime){
        if(!root || root==already_burnt)return ;
        res = max(res, curtime);
        burnchild(root->left,already_burnt, curtime+1);
        burnchild(root->right,already_burnt, curtime+1);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends