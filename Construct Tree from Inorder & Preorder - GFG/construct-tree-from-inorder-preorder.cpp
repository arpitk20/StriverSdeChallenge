//{ Driver Code Starts
//

#include<bits/stdc++.h>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int Find(int in[], int target, int start, int end)
    {
        for(int i=start;i<=end;i++)
            if(in[i]==target)
                return i;
                
        return -1;
    }
    Node* Tree(int in[],int pre[], int start, int end, int index)
    {
        if(start>end)
            return NULL;
            
        //Build the node
        Node* root = new Node(pre[index]);
        //Find the index in inorder
        int i = Find(in, pre[index], start, end);
        
        root->left = Tree(in, pre, start, i-1, index+1);
        root->right = Tree(in, pre, i+1, end, index+(i-start)+1);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root;
        root = Tree(in, pre, 0, n-1, 0);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends