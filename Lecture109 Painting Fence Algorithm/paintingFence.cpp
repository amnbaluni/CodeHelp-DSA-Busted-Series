https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208

Recursion  SC = O(1) TC = exp
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

int solve(int n, int k){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
    }
    int ans = add(mul(solve(n-2,k), k-1), mul(solve(n-1,k),k-1));
    return ans;
}

int numberOfWays(int n, int k) {
      return solve(n,k);
}


Recursion + Memo   SC = O(N) TC = O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

int solveMemo(int n, int k, vector<int>&dp){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = add(mul(solveMemo(n-2,k,dp), k-1), mul(solveMemo(n-1,k,dp),k-1));
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solveMemo(n,k,dp);
}


Recursion + Tabu   SC = O(N) TC = O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

int solveTabu(int n, int k){
    vector<int>dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
    return solveTabu(n,k);
}


Recursion + Space Optimization SC = O(1) TC = O(N)
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

int solveTabu(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    for(int i=3; i<=n; i++){
        int ans = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    return solveTabu(n,k);
}

**************************************************************************************************************
More Simple Solution
int numberOfWays(int n, int k) {
    int dp[n+1];
    int MOD = 1e9+7;
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k*k;
    for(int i=3; i<=n; i++){
        dp[i] = ((k-1)*(dp[i-2] + dp[i-1]))%MOD;
    }
    return dp[n];
}
