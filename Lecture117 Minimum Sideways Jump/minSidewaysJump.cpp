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


Recursion + Memo
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
