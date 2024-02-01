I have used previous ques solution and just added k as a parameter
Optimized solution is  => TC = O(n*k) SC = O(k)

int solveTab(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit = 1; limit<=k; limit++){
                    int profit = 0;
                    //buy wala case
                    if(buy){
                       int buyKaro = -prices[index] + next[0][limit];
                       int skipKaro = 0 + next[1][limit];
                       profit = max(buyKaro, skipKaro);
                    }
                    //sell wala case
                    else{
                       int sellKaro = prices[index] + next[1][limit-1];
                       int skipKaro = 0 + next[0][limit];
                       profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][k];
    } 
    
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }


Another Solution using Transaction Number/Operation Number
Recursion
int solve(int index, int operationNo, int k, vector<int>& prices){
        //base case1
        if(index == prices.size()){
            return 0;
        }

        //base case2
        if(operationNo == 2*k){
            return 0;
        }
        int profit = 0;
        //we will buy only when operationNo is even
        if(operationNo % 2 == 0){
            int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        //we will sell only when operationNo is odd
        else{
            int sellKaro = prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k, prices);
    }


Recursion + Memo  SC=O(n*k) TC=O(n*k)
int solveMemo(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>> &dp){
        //base case1
        if(index == prices.size()){
            return 0;
        }

        //base case2
        if(operationNo == 2*k){
            return 0;
        }
        int profit = 0;
        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }
        //we will buy only when operationNo is even
        if(operationNo % 2 == 0){
            int buyKaro = -prices[index] + solveMemo(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solveMemo(index+1, operationNo, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        //we will sell only when operationNo is odd
        else{
            int sellKaro = prices[index] + solveMemo(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solveMemo(index+1, operationNo, k, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][operationNo] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
        return solveMemo(0, 0, k, prices, dp);
    }  

Recursion + Tabu   SC=O(n*k) TC=O(n*k)
int solveTabu(int k, vector<int>& prices){
        int n = prices.size();
        int profit = 0;
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++) {
                if(operationNo % 2 == 0){
                int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, skipKaro);
               }
            //we will sell only when operationNo is odd
             else{
                int sellKaro = prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(sellKaro, skipKaro);
            }
             dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTabu(k, prices);
    }  

Space Optimization   SC=O(k) TC=O(n*k)
int solveTabu(int k, vector<int>& prices) {
  int n = prices.size();
  int profit = 0;
  vector<int> curr(2 * k + 1, 0);
  vector<int> next(2 * k + 1, 0);
  for (int index = n - 1; index >= 0; index--) {
    for (int operationNo = 0; operationNo < 2 * k; operationNo++) {
      if (operationNo % 2 == 0) {
        int buyKaro = -prices[index] + next[operationNo + 1];
        int skipKaro = 0 + next[operationNo];
        profit = max(buyKaro, skipKaro);
      }
      // we will sell only when operationNo is odd
      else {
        int sellKaro = prices[index] + next[operationNo + 1];
        int skipKaro = 0 + next[operationNo];
        profit = max(sellKaro, skipKaro);
      }
      curr[operationNo] = profit;
    }
    next = curr;
  }
  return curr[0];
}
int maxProfit(int k, vector<int>& prices) { 
  return solveTabu(k, prices); 
}
