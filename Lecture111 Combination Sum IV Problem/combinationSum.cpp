https://www.naukri.com/code360/problems/number-of-ways_3755252

Recursion  TC = exp
#include <bits/stdc++.h> 
int solve(vector<int> &num, int tar){
    //base case
    if(tar == 0){
        return 1;
    }
    if(tar < 0){
        return 0;
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans = ans + solve(num, tar - num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

Recursion + Memo  TC = O(tar)
#include <bits/stdc++.h> 
int solveMemo(vector<int> &num, int tar, vector<int> &dp){
    //base case
    if(tar == 0){
        return 1;
    }
    if(tar < 0){
        return 0;
    }

    if(dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans = ans + solveMemo(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{ 
    vector<int> dp(tar+1, -1);
    return solveMemo(num, tar, dp);
}  

Recursion + Tabu   TC = O(tar*tar)
#include <bits/stdc++.h> 
int solveTabu(vector<int> &num, int tar){
    vector<int>dp(tar+1, 0);
    dp[0] = 1;
    //traversing from 1 to remaining target
    for(int i=1; i<=tar; i++){
        for(int j=0; j<num.size(); j++){
          if (i - num[j] >= 0) {
            dp[i] = dp[i] + dp[i - num[j]];
          }
     }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{ 
    return solveTabu(num, tar);
}  
