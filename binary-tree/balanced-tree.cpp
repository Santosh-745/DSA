/*
Logic was to get leftHight, rightHiht along woth the answers from left & right. 
  if 
    getting false any where return false without checking condition
  else 
    both sides are balanced than check for self by ans = (|lh - rh| <= 1)
  return { ans, max(lh, rh) + 1 };

input: 1 39 10 5 N N N
*/

#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    private:
    pair<bool, int> solve(Node* root) {
        if (!root) {
            return {true, 0};
        }
        
        pair<bool, int> leftPair = solve(root->left);
        pair<bool, int> rightPair = solve(root->right);
        
        bool leftAns = leftPair.first, 
             rightAns = rightPair.first;
        int leftHight = leftPair.second,
            rightHight = rightPair.second;
            
        if (!leftAns || !rightAns) return {false, -1};
        
        bool ans = (abs(leftHight - rightHight) <= 1);
        int hight = max(leftHight, rightHight) + 1;
        
        return {ans, hight};
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        pair<bool, int> p = solve(root);
        return p.first;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {
    string s, ch;
    getline(cin, s);
    
    Node* root = buildTree(s);
    Solution ob;
    cout << ob.isBalanced(root) << endl;
    return 0;
}

// } Driver Code Ends
