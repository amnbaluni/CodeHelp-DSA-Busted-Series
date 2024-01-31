Buy case = add profit and price with -ve sign
Sell case = add profit and price with +ve sign

Recursion
int solve(int index, int buy, vector<int>& prices){
        //base case
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        //buy wala case
        if(buy){
            int buyKaro = -prices[index] + solve(index+1, 0, prices);
            int skipKaro = 0 + solve(index+1, 1, prices);
            profit = max(buyKaro, skipKaro);
        }
        //sell wala case
        else{
            int sellKaro = prices[index] + solve(index+1, 1, prices);
            int skipKaro = 0 + solve(index+1, 0, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);
    }

Recursion + Memo  TC=SC=O(n)
int solveMemo(int index, int buy, vector<int>& prices, vector<vector<int>> &dp){
        //base case
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        //buy wala case
        if(buy){
            int buyKaro = -prices[index] + solveMemo(index+1, 0, prices, dp);
            int skipKaro = 0 + solveMemo(index+1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        //sell wala case
        else{
            int sellKaro = prices[index] + solveMemo(index+1, 1, prices, dp);
            int skipKaro = 0 + solveMemo(index+1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solveMemo(0, 1, prices, dp);
    }  


Recursion + Tabu  SC=O(n) = TC
int solveTabu(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
               int profit = 0;
               //buy wala case
               if(buy){
                   int buyKaro = -prices[index] + dp[index+1][0];
                   int skipKaro = 0 + dp[index+1][1];
                   profit = max(buyKaro, skipKaro);
                }
               //sell wala case
               else{
                   int sellKaro = prices[index] + dp[index+1][1];
                   int skipKaro = 0 + dp[index+1][0];
                   profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        return solveTabu(prices);
    }


Space Optimization  TC=O(n)  SC=O(1)
int solveTabu(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
               int profit = 0;
               //buy wala case
               if(buy){
                   int buyKaro = -prices[index] + next[0];
                   int skipKaro = 0 + next[1];
                   profit = max(buyKaro, skipKaro);
                }
               //sell wala case
               else{
                   int sellKaro = prices[index] + next[1];
                   int skipKaro = 0 + next[0];
                   profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

    int maxProfit(vector<int>& prices) {
        return solveTabu(prices);
    }
