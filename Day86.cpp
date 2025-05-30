class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inorder(Node* root,vector<int> &ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};
