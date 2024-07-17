https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

Recursion
int solve(vector<vector<int>> mat, int i, int j, int &maxi){
        //base case
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        //now I will have three choices
        int right = solve(mat, i, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        
        if(mat[i][j] == 1){
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        solve(mat, 0, 0, maxi);
        return maxi;
    }


Recursion + Memo    TC=SC= O(n*m)
int solveMemo(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>>&dp){
        //base case
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //now I will have three choices
        int right = solveMemo(mat, i, j+1, maxi, dp);
        int down = solveMemo(mat, i+1, j, maxi, dp);
        int diagonal = solveMemo(mat, i+1, j+1, maxi, dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int maxi = 0;
        solveMemo(mat, 0, 0, maxi, dp);
        return maxi;
    }

 
Recursion + Tabu    TC=SC= O(n*m)
int solveTabu(vector<vector<int>> &mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
        
                if(mat[i][j] == 1){
                   dp[i][j] = 1 + min(right, min(down, diagonal));
                   maxi = max(maxi, dp[i][j]);
                }
                else{
                   dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
int maxSquare(int n, int m, vector<vector<int>> mat){
  int maxi = 0;
  solveTabu(mat, maxi);
  return maxi;
}

Space Optimization  SC=O(m)
int space_optimization(vector<vector<int>> &mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        vector<int>curr(col+1, 0);
        vector<int>next(col+1, 0);
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                int right = curr[j+1];
                int down = next[j];
                int diagonal = next[j+1];
        
                if(mat[i][j] == 1){
                   curr[j] = 1 + min(right, min(down, diagonal));
                   maxi = max(maxi, curr[j]);
                }
                else{
                   curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        space_optimization(mat, maxi);
        return maxi;
    }

Solution 2 -> SC=O(1)
int space_optimization1(int m ,int n, vector<vector<int>>&mat){
        int maxi = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int down = i<n-1?mat[i+1][j]:0;
                int right = j<m-1? mat[i][j+1]:0;
                int diag = i<n-1 and j<m-1? mat[i+1][j+1]:0;
                // if(dp[i][j] == 1)
                if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(down,min(right, diag));
                    maxi = max(mat[i][j],maxi);
                }
            }
        }
        return maxi;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        space_optimization1(m,n,mat);
    }  
