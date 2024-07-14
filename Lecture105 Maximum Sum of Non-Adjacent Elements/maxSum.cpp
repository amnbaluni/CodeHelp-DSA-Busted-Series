https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

Using Recursion
#include <bits/stdc++.h>
int solve(vector<int> &nums, int n){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    
    //include condition
    int include = solve(nums, n-2) + nums[n];
    //exclude condition
    int exclude = solve(nums, n-1) + 0;

    return max(include, exclude);
} 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //startin from last index
    int ans = solve(nums, n-1);
    return ans;
}

Using Recursion + Memoization  TC = O(N); SC = O(n)+O(n)
int solveMemo(vector<int> &nums, int n, vector<int> &dp){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    //include condition
    int include = solveMemo(nums, n-2, dp) + nums[n];
    //exclude condition
    int exclude = solveMemo(nums, n-1, dp) + 0;

    dp[n] = max(include, exclude); 

    return dp[n];
} 


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMemo(nums, n-1, dp);
}

Using Recursion + Tabulation  TC = SC = O(N)
#include <bits/stdc++.h>
int solveTabu(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums) {
    return solveTabu(nums);
}


SPACE OPTIMIZATION - TC = (n)  SC = O(1)
int spaceOpti(vector<int> &nums){
    //space optimization - doing without dp array
    int n = nums.size();
    int prev2 = 0; 
    int prev1 = nums[0];
  
    for(int i=1; i<=n; i++){
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
} 
int maximumNonAdjacentSum(vector<int> &nums) {
    return spaceOpti(nums);
}
************************************************************
//Starting from first index    
int solveMemo(vector<int> &nums, int i, vector<int> &dp){
    //base case
    if(i >= nums.size()){
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    //include condition
    int include = solveMemo(nums, i+2, dp) + nums[i];
    //exclude condition
    int exclude = solveMemo(nums, i+1, dp) + 0;

    return dp[i] = max(include, exclude);
} 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMemo(nums, 0, dp);
}
