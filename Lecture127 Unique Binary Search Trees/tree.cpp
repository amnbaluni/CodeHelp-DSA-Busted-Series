https://leetcode.com/problems/unique-binary-search-trees/

The formula is represented by f(n) = ∑[ f(i-1) * f(n-i) ]

Recursion
int numTrees(int n) {
        if(n==0 || n==1){
            //dono hi case mein
            return 1;
        }
        int ans = 0;
        //traversing all nodes -> think i as root node in each iteration
        for(int i=1; i<=n ;i++){
            ans = ans + numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }


Recursion + Memo    TC = O(n*n)  SC=O(n)
int solveMemo(int n, vector<int> &dp){
        if(n==0 || n==1){
            //dono hi case mein
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        //travsersing all nodes -> think i as root node in each iteration
        for(int i=1; i<=n ;i++){
            ans = ans + solveMemo(i-1, dp) * solveMemo(n-i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solveMemo(n, dp);
    }  


Recursion + Tabu  TC = O(n*n)  SC=O(n)
int solveTabu(int n){
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 1;
        //i-> kitne no. of nodes ko consider kar rhe ho
        for(int i=2; i<=n; i++){
            //j-> kisko root node maan rhe ho
            //j kahan tak jayega -> jitni nodes present hai i.e i
            for(int j=1; j<=i; j++){
                dp[i] = dp[i] + dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        return solveTabu(n);
    }  

Space Optimization => This question can be solved using Catalan Number in O(1) Space Complexity. Catalan number series will give you exactly same ans for n.
You simply need to print Catalan number for a given number of nodes
other question is - Intersection Chords in a Circle problem

    double ncr(int n, int r) {
        if (r == 0){
            return 1;
        }
        if (r == n){
            return 1;
        }

        return (n * ncr(n - 1, r - 1)) / r;
    }
    int numTrees(int n) { 
        return ncr(2 * n, n) / (n + 1); 
    }
