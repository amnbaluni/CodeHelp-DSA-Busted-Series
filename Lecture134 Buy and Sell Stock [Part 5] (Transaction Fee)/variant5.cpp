TC = O(n)   SC = O(1)

int solveTabu(vector<int>& prices, int fee){
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
                   int sellKaro = prices[index] + next[1] - fee;
                   int skipKaro = 0 + next[0];
                   profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveTabu(prices, fee);
    }
