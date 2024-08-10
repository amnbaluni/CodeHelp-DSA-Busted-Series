https://www.naukri.com/code360/problems/0-1-knapsack_920542

Recursion
#include <bits/stdc++.h> 
int solve(vector<int>& weight, vector<int>& value, int index, int capacity){
	//base case
	//if there is only 1 item to steal, then compare it's weight with maxWeight
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}
		else{
			//weight is greater
			return 0;
		}
	}
	
    int include = 0;
    if (weight[index] <= capacity) {
        include = solve(weight, value, index - 1, capacity - weight[index]) + value[index];
    }

    int exclude = solve(weight, value, index - 1, capacity) + 0;
    int ans = max(include, exclude);
	return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, n-1, maxWeight);
}

Recursion + Memoization TC = SC = O(n*maxWeight)
#include <bits/stdc++.h> 
#include <vector>

int solveMemo(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>> &dp){
	//base case
	//if there is only 1 item to steal, then compare it's weight with maxWeight
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}
		else{
			//weight is greater
			return 0;
		}
	}

	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

    int include = 0;
    if (weight[index] <= capacity) {
        include = solveMemo(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }

    int exclude = solveMemo(weight, value, index - 1, capacity, dp) + 0;
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solveMemo(weight, value, n-1, maxWeight, dp);
}  

Recursion + Tabu      TC = SC = O(n*maxWeight)
#include <bits/stdc++.h> 
#include <vector>

int solveTabu(vector<int>& weight, vector<int>& value, int n, int capacity){
	//step1 : create dp array (which is 2D) and initialize it to 0
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	//step2 : analyze base cases
	for(int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
                     dp[0][w] = value[0];
		}
		else{
		     dp[0][w] = 0;
		}
	}

    //step3 : take care of remaining recursive calls
    //rows - 0 to n 
    //cols - 0 to capacity + 1	
	for(int index = 1; index<n; index++){
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + dp[index-1][w-weight[index]];
			}

			int exclude = 0 + dp[index-1][w];
			dp[index][w] = max(include, exclude);
		}
	}
	return dp[n-1][capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	return solveTabu(weight, value, n-1, maxWeight);
}

Space Optimization (with two vectors) TC = O(n*maxWeight) SC=O(2*maxWeight)
#include <bits/stdc++.h> 
#include <vector>

int solveTabu(vector<int>& weight, vector<int>& value, int n, int capacity){
	//step1 : create only two vector prev and curr
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
	
	//step2 : analyze base cases
	for(int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
           prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
	}

    //step3 : take care of remaining recursive calls
	for(int index = 1; index<=n; index++){
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + prev[w-weight[index]];
			}

			int exclude = 0 + prev[w];
			curr[w] = max(include, exclude);
		}
	}
	return prev[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTabu(weight, value, n-1, maxWeight);
}


Space Optimization (with one vector)   TC = O(n*maxWeight) SC=O(maxWeight)
#include <bits/stdc++.h> 
#include <vector>
//Traversing from right to left for capacity - here we need only one vector -> curr
int solveTabu(vector<int>& weight, vector<int>& value, int n, int capacity){
	//step1 : create only one vector curr
	vector<int> curr(capacity+1, 0);
	
	//step2 : analyze base cases
	for(int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
           curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
	}

  //step3 : take care of remaining recursive calls
	for(int index = 1; index<=n; index++){
		for(int w=capacity; w>=0; w--){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + curr[w-weight[index]];
			}

			int exclude = 0 + curr[w];
			curr[w] = max(include, exclude);
		}
	}
	return curr[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTabu(weight, value, n-1, maxWeight);
}
