class Solution {
  public:
    unordered_map<int,int> mp;
    Node *solve(vector<int> &preorder,int s,int e,int &preInd){
        if(s>e) return NULL;
        int val=preorder[preInd];
        Node* root=new Node(preorder[preInd++]);
        root->left=solve(preorder,s,mp[val]-1,preInd);
        root->right=solve(preorder,mp[val]+1,e,preInd);
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preInd=0;
        return solve(preorder,0,inorder.size()-1,preInd);
    }
};
