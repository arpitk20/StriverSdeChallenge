//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node


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


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(!r1||!r2)//if a single tree is NULL
            return false;
        
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(r1);
        q2.push(r2);
        vector<int> first, second;
        while(!q1.empty()||!q2.empty())
        {
            int n1 = q1.size();
            int n2 = q2.size();
            if(n1!=n2)
                return false;
            for(int i=0;i<n1;i++)
            {
                Node* temp = q1.front();
                q1.pop();
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
                first.push_back(temp->data);
            }
            for(int i=0;i<n2;i++)
            {
                Node* temp = q2.front();
                q2.pop();
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
                second.push_back(temp->data);
            }
        }
        if(first.size()!=second.size())
            return false;
        for(int i=0;i<first.size();i++)
        {
            if(first[i]!=second[i])
                return false;
            else
                continue;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, str1;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, str1);
        Node *rootB = buildTree(str1);
        Solution ob;
        if (ob.isIdentical(rootA, rootB)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends