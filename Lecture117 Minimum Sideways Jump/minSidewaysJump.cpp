Recursion
int solve(vector<int>& obstacles, int currLane, int currPos){
        int n = obstacles.size();
        //base case -> if frog reaches at the end
        if(currPos == n){
            return 0;
        }
        if(obstacles[currPos + 1] != currLane){
            return solve(obstacles, currLane, currPos + 1);
        }
        else{
           int ans = INT_MAX;
           for(int i=1; i<=3; i++){
            if(currLane != i && obstacles[currPos] != i){
                ans = min(ans, 1 + solve(obstacles, i, currPos));
             }
           }
        return ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0);
    }


Recursion + Memo SC=O(4*n)
int solveMemo(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>> &dp){
        int n = obstacles.size();
        //base case -> if frog reaches at the end
        if(currPos == n){
            return 0;
        }

        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos];
        }

        if(obstacles[currPos + 1] != currLane){
            return solveMemo(obstacles, currLane, currPos + 1, dp);
        }

        else{
        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(currLane != i && obstacles[currPos] != i){
                ans = min(ans, 1 + solveMemo(obstacles, i, currPos, dp));
            }
        }
        dp[currLane][currPos] = ans;;
        return dp[currLane][currPos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMemo(obstacles, 2, 0, dp);
    }  


Recursion + Tabu  SC=O(4*n)  TC=O(3*3*n)
int solveTabu(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        //initializing dp vector from base case
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1; currLane<=3; currLane++){
                if(obstacles[currPos + 1] != currLane){
                   dp[currLane][currPos] = dp[currLane][currPos + 1];
                }
                else{
                     int ans = 1e9;
                for(int i=1; i<=3; i++){
                   if(currLane != i && obstacles[currPos] != i){
                   ans = min(ans, 1 + dp[i][currPos+1]);
                 }
                dp[currLane][currPos] = ans;
                }
              }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        return solveTabu(obstacles);
    }        


Space Optimization  SC=O(1)  TC=O(3*3*n)
int solveTabu(vector<int>& obstacles){
        int n = obstacles.size()-1;
        //we only need two vectors in Space Optimization
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, 0);

        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1; currLane<=3; currLane++){
                if(obstacles[currPos + 1] != currLane){
                   curr[currLane] = next[currLane];
                }
                else{
                     int ans = 1e9;
                for(int i=1; i<=3; i++){
                   if(currLane != i && obstacles[currPos] != i){
                   ans = min(ans, 1 + next[i]);
                 }
                curr[currLane] = ans;
                }
              }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        return solveTabu(obstacles);
    }
