Recursion
int solveMemo(int n, int a[], int currIndex, int prevIndex){
        //base case
        if(currIndex == n){
            return 0;
        }
        //include condition
        int take = 0;
        if(prevIndex == -1 || a[currIndex]>a[prevIndex]){
            take = 1 + solveMemo(n, a, currIndex+1, currIndex);
        }
        //exclude condition
        int notTake = 0 + solveMemo(n, a, currIndex+1, prevIndex);
        return max(take, notTake);
    }
    int longestSubsequence(int n, int a[])
    {  
       return solveMemo(n, a, 0, -1);
    }

Recursion + Memo  TC = SC = O(n*n)
int solveMemo(int n, int a[], int currIndex, int prevIndex, vector<vector<int>> &dp){
        //base case
        if(currIndex == n){
            return 0;
        }
        if(dp[currIndex][prevIndex+1]!=-1){
            return dp[currIndex][prevIndex+1];
        }
        //include condition
        int take = 0;
        if(prevIndex == -1 || a[currIndex]>a[prevIndex]){
            take = 1 + solveMemo(n, a, currIndex+1, currIndex, dp);
        }
        //exclude condition
        int notTake = 0 + solveMemo(n, a, currIndex+1, prevIndex, dp);
        return dp[currIndex][prevIndex + 1] = max(take, notTake);
        
    }
    int longestSubsequence(int n, int a[])
    {  vector<vector<int>> dp(n, vector<int>(n+1, -1));
       return solveMemo(n, a, 0, -1, dp);
    }  

Recursion + Tabu     TC = SC = O(n*n)
int solveTabu(int n, int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int currIndex=n-1; currIndex>=0; currIndex--){
            for(int prevIndex=currIndex-1; prevIndex>=-1; prevIndex--){
                int take = 0;
                if(prevIndex == -1 || a[currIndex]>a[prevIndex]){
                   take = 1 + dp[currIndex+1][currIndex+1];
                }
               int notTake = 0 + dp[currIndex+1][prevIndex+1];
               dp[currIndex][prevIndex + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
    int longestSubsequence(int n, int a[])
    {  
       return solveTabu(n, a);
    }


Space Optimization   Sc=O(n) TC=O(n*n)
int solveTabu(int n, int a[]){
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int currIndex=n-1; currIndex>=0; currIndex--){
            for(int prevIndex=currIndex-1; prevIndex>=-1; prevIndex--){
                int take = 0;
                if(prevIndex == -1 || a[currIndex]>a[prevIndex]){
                   take = 1 + next[currIndex+1];
                }
               int notTake = 0 + next[prevIndex+1];
               curr[prevIndex + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
    int longestSubsequence(int n, int a[])
    {  
       return solveTabu(n, a);
    }
