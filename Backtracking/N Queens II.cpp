//https://leetcode.com/problems/n-queens-ii/

// 1. Place queens row by row.
// 2. For the current row, try every column.
// 3. Before placing a queen at (row, col), check:
//    - No queen exists in the same column above.
//    - No queen exists in the upper-left diagonal.
//    - No queen exists in the upper-right diagonal.
// 4. If the position is safe:
//     - Place the queen.
//     - Recursively solve for the next row.
//     - Backtrack by removing the queen.
// 5. When row == n, a valid arrangement of n queens is found, so return 1.
// 6. Sum the counts returned from all valid recursive calls to get the total number of distinct solutions.

// Time Complexity: O(N!)
// Space Complexity: O(N) recursion stack

class Solution {
public:
    bool isSafe(int r,int c,vector<string> &board,int n){
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }
// upper left
        for(int i=r-1,j=c-1;i>=0 && j>=0 ;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
//upper right
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    int solve(int row,int n,vector<string> &board){
        if(row==n) return 1;
        int count=0;
        for(int i=0;i<n;i++){
            if(isSafe(row,i,board,n)){
                board[row][i]='Q';
                count+=solve(row+1,n,board);
                board[row][i]='.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        return solve(0,n,board);
    }
};
