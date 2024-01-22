Recursion  TC=exp
int solve(int n, vector<int>& days, vector<int>& cost, int index){
    //base case
    if(index >= n){
        return 0;
    }

    //1 day pass
    int singleDay = cost[0] + solve(n, days, cost, index+1);

    int i;
    //7 day pass
    for(i = index; i<n && days[i] < days[index] + 7; i++);
    int sevenDay = cost[1] + solve(n, days, cost, i);

    //30 days pass
    for(i = index; i<n && days[i] < days[index] + 30; i++);
    int thirtyDay = cost[2] + solve(n, days, cost, i);

    //returning minimum of these three value
    return min(singleDay, min(sevenDay, thirtyDay));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, 0);
}


Recursion + Memoization  TC=O(365) = O(1)
int solveMemo(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp){
    //base case
    if(index >= n){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    //1 day pass
    int singleDay = cost[0] + solveMemo(n, days, cost, index+1, dp);

    int i;
    //7 day pass
    for(i = index; i<n && days[i] < days[index] + 7; i++);
    int sevenDay = cost[1] + solveMemo(n, days, cost, i, dp);

    //30 days pass
    for(i = index; i<n && days[i] < days[index] + 30; i++);
    int thirtyDay = cost[2] + solveMemo(n, days, cost, i, dp);

    //returning minimum of these three value
    dp[index] = min(singleDay, min(sevenDay, thirtyDay));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return solveMemo(n, days, cost, 0, dp);
}


Recursion + Tabulation  TC=O(n)  SC=O(n)  
int solveTabu(int n, vector<int> &days, vector<int> &cost) {
  vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;
  for (int k = n - 1; k >= 0; k--) {
    // 1 day pass
    int singleDay = cost[0] + dp[k + 1];

    int i;
    // 7 day pass
    for (i = k; i < n && days[i] < days[k] + 7; i++);
    int sevenDay = cost[1] + dp[i];

    // 30 days pass
    for (i = k; i < n && days[i] < days[k] + 30; i++);
    int thirtyDay = cost[2] + dp[i];

    // returning minimum of these three value
    dp[k] = min(singleDay, min(sevenDay, thirtyDay));
  }
  return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
  return solveTabu(n, days, cost);
}  


