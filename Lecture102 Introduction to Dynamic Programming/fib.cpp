//Using Memoization Method (top down approach)
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int fib(int n, vector<int> &dp){
        //base case
        if(n<=1){
                return n;
        }
        //step3: check if dp[n] is already calculated
        if(dp[n]!=-1){
                return dp[n];
        }
        //step2: recursive call
        dp[n] = fib(n-1, dp) + fib(n-2,dp);

        return dp[n];
}


int main()
{
       int n;
       cin>>n;
       vector<int> dp(n+1, -1);
//        for(int i=0; i<=n; i++){
//                dp[i] = -1;
//        }
      //step1
       cout<<fib(n,dp)<<endl;

       return 0;
}

TC = SC = O(n)

//Using Tabulation Method (bottom up approach)
int main()
{
       int n;
       cin>>n;
       vector<int>dp(n+1);
       dp[0] = 0;
       dp[1] = 1;
         
       for(int i=2; i<=n; i++){
               dp[i] = dp[i-1]+dp[i-2];
       }  

       cout<<dp[n]<<endl;
}

//Space Optimization
int main()
{
       int n;
       cin>>n;
       int prev1 = 1;
       int prev2 = 0;
       for(int i=2; i<=n; i++){
               int curr = prev1 + prev2;
               //sift kr do
               prev2 = prev1;
               prev1 = curr;
       }

       cout<<prev1<<endl;
       return 0;
}
TC = O(n) remains constant
SC = O(1) becomes constant
