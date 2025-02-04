
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int height(Node* root,int &ans){
        if(!root) return 0;
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        ans=max(ans,lh+rh);
        return max(lh,rh)+1;
    }
    int diameter(Node* root) {
        // Your code here
        int ans=0;
        height(root,ans);
        return ans;
    }
};
