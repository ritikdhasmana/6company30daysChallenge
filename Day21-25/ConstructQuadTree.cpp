/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return (n == 0) ? nullptr : build(grid, n, 0, 0);
    }
private :
    Node * build(vector<vector<int>> &g, int n, int i, int j){
        for(int x=i;x<i+n;x++){
            for(int y=j;y<j+n;y++){
                if(g[x][y]!=g[i][j]){
                    Node *tl = build(g,n/2,i,j);
                    Node *tr = build(g,n/2,i,j+n/2);
                    Node *bl = build(g,n/2,i+n/2,j);
                    Node *br = build(g,n/2,i+n/2,j+n/2);
                    return new Node(true,false,tl,tr,bl,br);
                }
            }
        }
        return new Node(g[i][j]==1,true,nullptr,nullptr,nullptr,nullptr);
    }
};
