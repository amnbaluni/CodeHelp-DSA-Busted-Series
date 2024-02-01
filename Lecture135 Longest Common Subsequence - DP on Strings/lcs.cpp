Recursion
int solve(string& text1, string& text2, int i, int j){
        //base case
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1, text2, i+1, j+1);
        }
        else{
            ans = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }

Recursion + Memo   TC=O(n1*n2)  SC=O(n1*n2)
int solveMemo(string& text1, string& text2, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solveMemo(text1, text2, i+1, j+1, dp);
        }
        else{
            ans = max(solveMemo(text1, text2, i+1, j, dp), solveMemo(text1, text2, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solveMemo(text1, text2, 0, 0, dp);
    }

Recursion + Tabu   TC=O(n1*n2)  SC=O(n1*n2)
int solveTabu(string& text1, string& text2){
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                  ans = 1 + dp[i+1][j+1];
                }
                else{
                  ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTabu(text1, text2);
    }  


Space Optimization  SC=O(n1) or O(n2)   TC=O(n1*n2)
int solveTabu(string& text1, string& text2){
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                  ans = 1 + next[j+1];
                }
                else{
                  ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTabu(text1, text2);
    }
