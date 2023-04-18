//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int minSubtreeLen = INT_MAX;
        findSubtreeSumBST(target, root, minSubtreeLen);
        return minSubtreeLen == INT_MAX ? -1 : minSubtreeLen;
    }

private:
    void findSubtreeSumBST(int target, Node* root, int& minSubtreeLen) {
        if (!root) {
            return;
        }

        if (isBST(root)) {
            int sum = getSum(root);
            if (sum == target) {
                int len = getSubtreeLength(root);
                minSubtreeLen = min(minSubtreeLen, len);
            }
        }

        findSubtreeSumBST(target, root->left, minSubtreeLen);
        findSubtreeSumBST(target, root->right, minSubtreeLen);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    bool isBSTUtil(Node* root, int minValue, int maxValue) {
        if (!root) {
            return true;
        }

        if (root->data < minValue || root->data > maxValue) {
            return false;
        }

        return isBSTUtil(root->left, minValue, root->data - 1) &&
               isBSTUtil(root->right, root->data + 1, maxValue);
    }

    int getSum(Node* root) {
        if (!root) {
            return 0;
        }

        return root->data + getSum(root->left) + getSum(root->right);
    }

    int getSubtreeLength(Node* root) {
        if (!root) {
            return 0;
        }

        return 1 + getSubtreeLength(root->left) + getSubtreeLength(root->right);

    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends