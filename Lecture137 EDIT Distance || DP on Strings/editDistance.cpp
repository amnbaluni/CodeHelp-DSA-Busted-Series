Recursion
int solve(string& a, string& b, int i, int j) {
  // base case1
  if (i == a.length()) {
    return b.length() - j;
  }
  // base case2
  if (j == b.length()) {
    return a.length() - i;
  }
  int ans = 0;
  if (a[i] == b[j]) {
    return solve(a, b, i + 1, j + 1);
  } else {
    // insert wala case
    int insertAns = 1 + solve(a, b, i, j + 1);
    // delete wala case
    int deleteAns = 1 + solve(a, b, i + 1, j);
    // replace wala case
    int replaceAns = 1 + solve(a, b, i + 1, j + 1);
    ans = min(insertAns, min(replaceAns, deleteAns));
  }
  return ans;
}

int editDistance(string str1, string str2) { 
  return solve(str1, str2, 0, 0); 
}


Recursion + Memo  TC=SC=O(n1*n2) 
int solveMemo(string& a, string& b, int i, int j, vector<vector<int>> &dp){
        //base case1
        if(i == a.length()){
            return b.length()-j;
        }
        //base case2
        if(j == b.length()){
            return a.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            return solveMemo(a, b, i+1, j+1, dp);
        }
        else{
            //insert wala case
            int insertAns = 1 + solveMemo(a, b, i, j+1, dp);
            //delete wala case
            int deleteAns = 1 + solveMemo(a, b, i+1, j, dp);
            //replace wala case
            int replaceAns = 1 + solveMemo(a, b, i+1, j+1, dp);
            ans = min(insertAns, min(replaceAns, deleteAns));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solveMemo(word1, word2, 0, 0, dp);
    }  


Recursion + Tabu   TC=SC=O(n1*n2) 
int solveTabu(string& a, string& b){
        int n1 = a.length();
        int n2 = b.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        //after analyzing the base case
        for(int j=0; j<n2; j++){
            dp[n1][j] = n2-j;
        }
        for(int i=0; i<n1; i++){
            dp[i][n2] = n1-i;
        }
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                  ans = dp[i+1][j+1];
                }
                else{
                 //insert wala case
                  int insertAns = 1 + dp[i][j+1];
                 //delete wala case
                  int deleteAns = 1 + dp[i+1][j];
                 //replace wala case
                  int replaceAns = 1 + dp[i+1][j+1];
                  ans = min(insertAns, min(replaceAns, deleteAns));
                }
                dp[i][j] = ans;
            }
        }
       return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return solveTabu(word1, word2);
    }

  
Space Optimi   TC=O(n1*n2)   SC=O(min(n1, n2))
int solveTabu(string& a, string& b){
        int n1 = a.length();
        int n2 = b.length();
        vector<int>curr(n2+1, 0);
        vector<int>next(n2+1, 0);
        
        //after analyzing the base case
        for(int j=0; j<n2; j++){
            next[j] = n2-j;
        }

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                //catch -> base case se mila ye
                curr[n2] = n1-i;
                int ans = 0;
                if(a[i] == b[j]){
                  ans = next[j+1];
                }
                else{
                 //insert wala case
                  int insertAns = 1 + curr[j+1];
                 //delete wala case
                  int deleteAns = 1 + next[j];
                 //replace wala case
                  int replaceAns = 1 + next[j+1];
                  ans = min(insertAns, min(replaceAns, deleteAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
       return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        return solveTabu(word1, word2);
    }
