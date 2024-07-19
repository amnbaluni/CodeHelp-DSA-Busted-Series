https://leetcode.com/problems/pizza-with-3n-slices/

Recursion
class Solution {
public:
    int solve(vector<int>&slices, int index, int endIndex, int n){
      //base case
      if(n==0 || index > endIndex){
          return 0;
      }

      int take = slices[index] + solve(slices, index+2, endIndex, n-1);
      int notTake = 0 + solve(slices, index+1, endIndex, n);
      return max(take, notTake);

    }
    int maxSizeSlices(vector<int>& slices) {
       int k = slices.size();
       int case1 = solve(slices, 0, k-2, k/3);
       int case2 = solve(slices, 1, k-1, k/3);
       return max(case1, case2);
    }
};


Recursion + Memo  SC=(k*k)  TC=O(k*k)
class Solution {
public:
    int solveMemo(vector<int>&slices, int index, int endIndex, int n, vector<vector<int>> &dp){
      //base case
        if(n==0 || index > endIndex){
          return 0;
        }
        if(dp[index][n] != -1){
            return dp[index][n];
        }

      int take = slices[index] + solveMemo(slices, index+2, endIndex, n-1, dp);
      int notTake = 0 + solveMemo(slices, index+1, endIndex, n, dp);
      return dp[index][n]  = max(take, notTake);

    }
    int maxSizeSlices(vector<int>& slices) {
       int k = slices.size();
       vector<vector<int>> dp1(k, vector(k, -1));
       int case1 = solveMemo(slices, 0, k-2, k/3, dp1);

       vector<vector<int>> dp2(k, vector(k, -1));
       int case2 = solveMemo(slices, 1, k-1, k/3, dp2);
       return max(case1, case2);
    }
};  


Recursion + Tabu    SC=(k*k)  TC=O(k*k)
class Solution {
public:
    int solveTabu(vector<int>&slices){
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k, 0));
        vector<vector<int>> dp2(k, vector<int>(k, 0));
        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int take = slices[index] + dp1[index+2][n-1];
                int notTake = 0 + dp1[index+1][n];
                dp1[index][n]  = max(take, notTake);
            }
        }

        int case1 = dp1[0][k/3];

        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int take = slices[index] + dp2[index+2][n-1];
                int notTake = 0 + dp2[index+1][n];
                dp2[index][n]  = max(take, notTake);
            }
        }

        int case2 = dp2[0][k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
       return solveTabu(slices);
    }
};


Space Opt SC=(6*k)  TC=O(k*k)
class Solution {
public:
       
    int solveTabu(vector<int>&slices){
        int k = slices.size();
        vector<int>prev1(k+2, 0);
        vector<int>curr1(k+2, 0);
        vector<int>next1(k+2, 0);

        vector<int>prev2(k+2, 0);
        vector<int>curr2(k+2, 0);
        vector<int>next2(k+2, 0);

        
        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int take = slices[index] + next1[n-1];
                int notTake = 0 + curr1[n];
                prev1[n]  = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }

        int case1 = curr1[k/3];

        for(int index=k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int take = slices[index] + next2[n-1];
                int notTake = 0 + curr2[n];
                prev2[n]  = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }

        int case2 = curr2[k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
    return solveTabu(slices);
    }
};
