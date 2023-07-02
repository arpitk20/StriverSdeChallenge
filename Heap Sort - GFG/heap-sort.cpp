//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int maxHeap[], int size, int index)  
    {
      // Your Code Here
      int largest = index;
      int left = 2*index+1;
      int right = 2*index+2;
      if(left<size && maxHeap[left]>maxHeap[largest])
            largest = left;
      if(right<size && maxHeap[right]>maxHeap[largest])
            largest = right;
        if(largest!=index)
        {
            swap(maxHeap[index], maxHeap[largest]);
            heapify(maxHeap, size, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        //create heap
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(arr, n, i);
        }
        //then sort
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends