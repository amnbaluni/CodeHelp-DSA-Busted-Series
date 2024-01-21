Recursion
int solve(int n){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    int ans = n;
	    for(int i=1; i*i<=n; i++){
	        ans = min(ans, 1+solve(n-i*i));
	    }
	    return ans;
	}
	int MinSquares(int n)
	{
	    return solve(n);
	}

Recursion + Memo
int solveMemo(int n, vector<int> &dp){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    int ans = n;
	    
	    for(int i=1; i*i<=n; i++){
	        ans = min(ans, 1+solveMemo(n-i*i, dp));
	    }
	    dp[n] = ans;
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1, -1);
	    return solveMemo(n,dp);
	}

Recursion + Tabu
int solveTabu(int n){
	    vector<int> dp(n+1, INT_MAX);
	    dp[0] = 0;
	    for(int i=1; i<=n; i++){
	        for(int j=1; j*j<=n; j++){
	            if(i-j*j >= 0){
	                dp[i] = min(dp[i], 1 + dp[i-j*j]);
	            }
	        }
	    }
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    return solveTabu(n);
	}
  
