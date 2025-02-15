#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to serialize a tree and return a list containing its data.
    vector<int> serialize(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (node) {
                result.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back(-1); // Placeholder for NULL
            }
        }
        return result;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &arr) {
        if (arr.empty()) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        
        while (!q.empty() && i < arr.size()) {
            Node* node = q.front();
            q.pop();
            
            if (arr[i] != -1) {
                node->left = new Node(arr[i]);
                q.push(node->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1) {
                node->right = new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Function for in-order traversal (to verify correctness)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Solution sol;
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> serializedTree = sol.serialize(root);
    cout << "Serialized Tree: ";
    for (int num : serializedTree) cout << num << " ";
    cout << endl;

    Node* deserializedRoot = sol.deSerialize(serializedTree);
    cout << "Inorder Traversal of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}
