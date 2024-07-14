https://www.naukri.com/code360/problems/count-derangements_873861

Recursion TC = exponential
#define MOD 1000000007
long long int countDerangements(int n) {
    //base case
    //if there is only 1 or 2 elements
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int ans = (((n-1)%MOD) * ((countDerangements(n-2)%MOD) + (countDerangements(n-1)%MOD)))%MOD;

    return ans;
}

Recursion + Memoization  TC = (N) SC = O(N)+O(N)
#include <vector>
#define MOD 1000000007
long long int solveMemo(int n, vector<long long int>&dp){
  //base case
    //if there is only 1 or 2 elements
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = (((n-1)%MOD) * ((solveMemo(n-2,dp)%MOD) + (solveMemo(n-1,dp)%MOD)))%MOD;

    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    return solveMemo(n,dp);
}

Recursion + Tabulation     TC = (N) SC = O(N)
#include <vector>
#define MOD 1000000007
long long int solveTabu(int n){
  vector<long long int>dp(n+1, 0);
  dp[1] = 0;
  dp[2] = 1;

  for(int i=3; i<=n; i++){
      long long int first = dp[i-1]%MOD;
      long long int second = dp[i-2]%MOD;
      long long sum = (first+second)%MOD;
      long long ans = ((i-1)*sum)%MOD;
      dp[i] = ans;
  }
  return dp[n];
}

long long int countDerangements(int n) {
    return solveTabu(n);
}

Space Optimization   TC = O(N)  SC = O(1)
#include <vector>
#define MOD 1000000007
long long int solveTabu(int n){

  long long int prev2 = 0;
  long long int prev1 = 1;

  for(int i=3; i<=n; i++){
      long long int first = prev1%MOD;
      long long int second = prev2%MOD;
      long long sum = (first+second)%MOD;
      long long ans = ((i-1)*sum)%MOD;
      prev2 = prev1;
      prev1 = ans;
  }
  return prev1;
}

long long int countDerangements(int n) {
    return solveTabu(n);
}
