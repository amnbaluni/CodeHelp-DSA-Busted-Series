https://leetcode.com/problems/minimum-score-triangulation-of-polygon

Recursion
int solve(vector<int>& v, int i, int j){
        //base case -> if the first and last vertex of polygon becomes adjacent
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0, n-1);   //initially -> i=0 & j=n-1
    }

Recursion + Memo
int solveMemo(vector<int>& v, int i, int j,  vector<vector<int>> &dp){
        //base case -> if first and last vertex of ploygon becomes adjacent
        if(i+1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solveMemo(values, 0, n-1, dp);
    }  


Recursion + Tabu    TC=O(n^3)   SC=O(n^2)
int solveTabu(vector<int>& v){
       int n = v.size();
       vector<vector<int>> dp(n, vector<int>(n,0));
       for(int i=n-1; i>=0; i--){
           for(int j=i+2; j<n; j++){  //imp -> start j from i+2
               int ans = INT_MAX;
               for(int k=i+1; k<j; k++){
               ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
               }
              dp[i][j] = ans;
           }
       }
       return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        return solveTabu(values);
    }


