//https://leetcode.com/problems/n-queens/description/

// 1. We place queens row by row.
// 2. For each row, try placing a queen in every column.
// 3. Before placing a queen at (row, col), check if it is safe:
  //    - No queen in the same column above.
  //    - No queen in the upper-left diagonal.
  //    - No queen in the upper-right diagonal.
// 4. If the position is safe:
  //    - Place the queen.
  //    - Recursively solve for the next row.
  //    - Backtrack by removing the queen to explore other possibilities.
// 5. When row == n, all queens are placed successfully,
  //    so store the current board configuration in the result.

// Time Complexity: O(N!)
// Space Complexity: O(N) recursion stack
    
  
class Solution {
public:
    vector<vector<string>> result;

    bool isValid(vector<string> &board,int row,int col,int n){
        //upward
        for(int i=row-1;i>=0;i--){
            if(board[i][col] =='Q')
            return false;
        }

        //left diagonal
        for(int i=row-1,j=col-1 ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j] =='Q')
            return false;
        }

        //right diagonal;
        for(int i=row-1,j=col+1 ; i>=0 && j<n ; i--,j++){
            if(board[i][j] =='Q')
            return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row,int n){
        if(row >= n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isValid(board,row,col,n)){
                board[row][col]='Q';
                solve(board,row+1,n);
                board[row][col]='.';
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return{};

        vector<string>board(n,string(n,'.')); //{'...','...','...'}
        solve(board,0,n);

        return result;
    }
};
