//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isPossible(int grid[N][N], int row, int col, int val)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[i][col]==val||grid[row][i]==val)
                return false;
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)
                return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int row=0;row<N;row++)
        {
            for(int col=0;col<N;col++)
            {
                if(grid[row][col]==0)
                {
                    for(int val=1;val<=N;val++)
                    {
                        if(isPossible(grid, row, col, val))
                        {
                            grid[row][col] = val;
                            if(SolveSudoku(grid))
                                return true;
                            else
                                grid[row][col] = 0;
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends