https://www.naukri.com/code360/problems/house-robber_839733

#include <bits/stdc++.h> 
long long solve(vector<int>&nums, int stInd, int n){
    long long prev2 = 0;
    long long prev1 = nums[stInd];
    for(int i=stInd+1; i<=n; i++){
        long long include = prev2 + nums[i];
        long long exclude = prev1 + 0;
        long long ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1){
        return valueInHouse[0];
    }  


// case 1 he robbs 1st house and excludes last
// 0-based indexing
    long long sum1 = solve(valueInHouse, 0, n-2);

// case2 he excludes 1st and robbs last
// 0-based indexing
    long long sum2 = solve(valueInHouse, 1, n-1);
    return max(sum1, sum2);
} 

TC = O(N)
SC = O(1)  
