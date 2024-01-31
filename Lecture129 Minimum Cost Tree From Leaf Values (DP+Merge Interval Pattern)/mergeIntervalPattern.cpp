Recursion
int solve(vector<int>& arr, map<pair<int,int>,int> &maxi, int left, int right){
       //base case -> when leaf nodes becomes same
       if(left == right){
           return 0;
       }
       int ans = INT_MAX;
       for(int i=left; i<right; i++){
           ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
       }
       return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        //make a map that will map pair with max values
        map<pair<int,int>, int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
               maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        return solve(arr, maxi, 0, arr.size()-1);
    }


Recursion + Memo
int solveMemo(vector<int>& arr, map<pair<int,int>,int> &maxi, int left, int right, vector<vector<int>> &dp){
       //base case -> when leaf nodes becomes same
       if(left == right){
           return 0;
       }
       if(dp[left][right] != -1){
           return dp[left][right];
       }
       int ans = INT_MAX;
       for(int i=left; i<right; i++){
           ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solveMemo(arr, maxi, left, i, dp) + solveMemo(arr, maxi, i+1, right, dp));
       }
       return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        //make a map that will map pair with max values
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
               maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        return solveMemo(arr, maxi, 0, n-1, dp);
    }  


Recursion +  Tabu  TC=O(n*n*n)  SC=O(n*n)
int solveTabu(vector<int>& arr, map<pair<int, int>, int>& maxi) {
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int left = n - 1; left >= 0; left--) {
    for (int right = left; right < n; right++) {
      if (left == right) {
        continue;
      } 
      else {
        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
          ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] +
                             dp[i + 1][right]);
        }
        dp[left][right] = ans;
      }
    }
  }
  return dp[0][n - 1];
}

int mctFromLeafValues(vector<int>& arr) {
  // make a map that will map pair with max values
  map<pair<int, int>, int> maxi;
  int n = arr.size();

  for (int i = 0; i < arr.size(); i++) {
    maxi[{i, i}] = arr[i];
    for (int j = i + 1; j < arr.size(); j++) {
      maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
    }
  }
  return solveTabu(arr, maxi);
}


Another solution
int solve(vector<int>&arr,int start,int end,  vector<vector<int>>&dp)
    {
        if(start >= end) return 0;

        if(dp[start][end] != -1) return dp[i][j];

        int ans=INT_MAX;
        for(int k=start; k<end; k++)
        {
            //left Partition
            int left=solve(arr,start,k,dp);
			//Right Partion
            int right=solve(arr,k+1,end,dp);
			//maximum value in left partion
            int max_left=*max_element(arr.begin()+start, arr.begin()+k+1);
			//maximum value in right partion.
            int max_right=*max_element(arr.begin()+k+1, arr.begin()+end+1);
			// As we to find temprorary answer.
            int temp=left+right+max_left*max_right;
			//Minum of all answer
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        return solve(arr,0,arr.size()-1,dp);
    }

Using Stack  TC = SC = O(n)
int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : arr) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
}

Space Opti is not possible
