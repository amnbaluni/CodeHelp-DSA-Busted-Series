Recursion
bool solve(int index, int arr[], int N, int target){
        //base case
        if(target < 0){
            return 0;
        }
        if(index >= N){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        bool include = solve(index+1, arr, N, target - arr[index]);
        bool exclude = solve(index+1, arr, N, target);
        bool ans = include || exclude;
        return ans;
    }
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total = total + arr[i];
        }
        
        if(total & 1){
            return 0;
        }
        
        int target = total/2;
        return solve(0, arr, N, target);
    }


Recursion + Memo  SC=O(N*target)
bool solveMemo(int index, int arr[], int N, int target, vector<vector<int>> &dp){
        //base case
        if(target < 0){
            return 0;
        }
        if(index >= N){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool include = solveMemo(index+1, arr, N, target - arr[index], dp);
        bool exclude = solveMemo(index+1, arr, N, target, dp);
        bool ans = include || exclude;
        return dp[index][target] = ans;
    }
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total = total + arr[i];
        }
        
        if(total & 1){
            return 0;
        }
        
        int target = total/2;
        vector<vector<int>> dp(N, vector<int>(target + 1, -1));
        return solveMemo(0, arr, N, target, dp);
    }  



Recursion + Tabu   SC=O(N*target)
bool solveTabu(int N, int arr[], int t){
        vector<vector<int>> dp(N+1, vector<int>(t + 1, 0));
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index>=0; index--){
            for(int target = 0; target<=t; target++){
                bool include = 0;
                if(target - arr[index] >= 0){
                   include = dp[index+1][target - arr[index]];
                }
                bool exclude = dp[index+1][target];
                bool ans = include || exclude;
                dp[index][target] = ans;
            }
        }
        return dp[0][t];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total = total + arr[i];
        }
        
        if(total & 1){
            return 0;
        }
        
        int t = total/2;
        vector<vector<int>> dp(N, vector<int>(t + 1, -1));
        return solveTabu(N, arr, t);
    } 

Space Optimization  SC=O(1)
bool solveTabu(int N, int arr[], int t){
        vector<int> curr(t+1, 0);
        vector<int> next(t+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1; index>=0; index--){
            for(int target = 0; target<=t; target++){
                bool include = 0;
                if(target - arr[index] >= 0){
                   include = next[target - arr[index]];
                }
                bool exclude = next[target];
                bool ans = include || exclude;
                curr[target] = ans;
            }
            next = curr;
        }
        return curr[t];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total = total + arr[i];
        }
        
        if(total & 1){
            return 0;
        }
        
        int t = total/2;
        vector<vector<int>> dp(N, vector<int>(t + 1, -1));
        return solveTabu(N, arr, t);
    }
