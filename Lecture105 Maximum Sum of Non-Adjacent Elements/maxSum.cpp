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
    int ans = solve(nums, n-1);
    return ans;
}

Using Recursion + Memoization  TC = SC = O(N)
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
    int include = solve(nums, n-2) + nums[n];
    //exclude condition
    int exclude = solve(nums, n-1) + 0;

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

int solve(vector<int> &nums, int stInd, int n){
    int prev2 = 0;
    int prev1 = nums[stInd];
    for(int i=stInd+1; i<=n; i++){
        int ans = max(nums[i]+prev2, prev1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
} 


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }  


// case 1 he robbs 1st house and excludes last
// 0-based indexing
    int sum1 = solve(nums, 0, n-1);

// case2 he excludes 1st and robbs last
// 0-based indexing
    int sum2 = solve(nums, 1, n-1);
    return max(sum1, sum2);
}  

SPACE OPTIMIZATION
int solveTabu(vector<int> &nums){
    //space optimization - doing with dp array
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
