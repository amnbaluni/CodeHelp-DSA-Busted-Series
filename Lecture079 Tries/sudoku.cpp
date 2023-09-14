#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>>& board, int val){
  for (int i = 0; i<board.size(); i++) {
    // check row
    if(board[row][i]==val){
        return false;
    }
    //check col
    if(board[i][col]==val){
        return false;
    }
    //check 3x3 matrix
    if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val){
        return false;
    }
  }
  return true;
}

bool solve(vector<vector<int>>& board){
    int n = board.size();
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            //check is cell empty
            if(board[row][col]==0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col]==val;
                    
                    ///recursive call
                       bool aagekaSolution = solve(board);
                       if(aagekaSolution){
                          return true;
                        } 
                        else {
                        // do backtrack
                          board[row][col] = 0;
                       }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}

//Time Complexity
TC = 9^(m) where m = number of empty cells
//Space Complexity
SC = O(1)
