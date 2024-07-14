https://www.naukri.com/code360/problems/cut-into-segments_1214651

Recursion TC = exponential
#include <limits.h>
int solve(int n, int x, int y, int z){
	//base case
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;   //ans nikalna is impossible
	}

	int a = solve(n-x,x,y,x) + 1; 
	int b = solve(n-y,x,y,x) + 1;
	int c = solve(n-z,x,y,x) + 1;

	int ans = max(a,max(b,c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n,x,y,z);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}

Recursion + Memoization   TC = O(N)  SC = O(N)+O(N)
#include <limits.h>
int solveMemo(int n, int x, int y, int z, vector<int> &dp) {
  if (n == 0) {
    return 0;
  }
  if (n < 0) {
    return INT_MIN;   //ans nikalna is impossible
  }
  if (dp[n] != -1) {
    return dp[n];
  }

  int a = solveMemo(n - x, x, y, z, dp) + 1;
  int b = solveMemo(n - y, x, y, z, dp) + 1;
  int c = solveMemo(n - z, x, y, z, dp) + 1;
  int ans = max(a, max(b, c));

  dp[n] = ans;
  return ans;
}
int cutSegments(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);   //0 based indexing
  int ans = solveMemo(n, x, y, z, dp);
  if (ans < 0) {
    return 0;
  }
  return ans;
}


Recursion + Tabulation TC = SC = O(N)
#include <limits.h>

int solveTabu(int n, int x, int y, int z){
	vector<int> dp(n+1, -1);
        dp[0] = 0;
	for(int i=1; i<=n; i++){
           //check for invalid index
	   if(i-x >= 0 && dp[i-x] != -1){
              dp[i] = max(dp[i], dp[i-x]+1);
	   }
	   if(i-y >= 0 && dp[i-y] != -1){
              dp[i] = max(dp[i], dp[i-y]+1);
	   } 
	   if(i-z >= 0 && dp[i-z] != -1){
              dp[i] = max(dp[i], dp[i-z]+1);
	   }
	}
	if(dp[n]<0){
		return 0;
	}
	else{
		return dp[n];
	}
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solveTabu(n,x,y,z);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}  
