https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

Recursion
int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        //base case
        if(index == nums1.size()){
            return 0;
        } 
        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        //here is the main catch
        if(swapped){
            swap(prev1, prev2);
        }
        //no swap case
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(nums1, nums2, index+1, 0);
        }

        //swap case
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1+solve(nums1, nums2, index+1, 1));
        }
        return ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 at beginning
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //we have to check whether previous indexes are swapped or not
        bool swapped = 0;
        return solve(nums1, nums2, 1, swapped);
    }



Recursion + Memo    TC = SC = O(n)
int solveMemo(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        //base case
        if(index == nums1.size()){
            return 0;
        } 
        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped){
            swap(prev1, prev2);
        }
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }
        //no swap case
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveMemo(nums1, nums2, index+1, 0, dp);
        }

        //swap case
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1+solveMemo(nums1, nums2, index+1, 1, dp));
        }
        return dp[index][swapped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 at beginning
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //we have to check whether previous indexes are swapped or not
        bool swapped = 0;
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveMemo(nums1, nums2, 1, swapped, dp);
    }  


Recursion + Tabu    TC = SC = O(n)
int solveTabu(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int index = n-1; index>=1; index--){
            for(int swapped = 1; swapped>=0; swapped--){
               int ans = INT_MAX;
               int prev1 = nums1[index-1];
               int prev2 = nums2[index-1];
               if(swapped){
                   swap(prev1, prev2);
                }
               //no swap case
                if(nums1[index] > prev1 && nums2[index] > prev2){
                   ans = dp[index+1][0];
                }
                //swap case
               if(nums1[index] > prev2 && nums2[index] > prev1){
                  ans = min(ans, 1+dp[index+1][1]);
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 at beginning
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //we have to check whether previous indexes are swapped or not
        bool swapped = 0;
        int n = nums1.size();
        
        return solveTabu(nums1, nums2);
    }



Space Optimization    SC = O(1)
int solveTabu(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        //we need only 4 variables
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for(int index = n-1; index>=1; index--){
            for(int swapped = 1; swapped>=0; swapped--){
               int ans = INT_MAX;
               int prev1 = nums1[index-1];
               int prev2 = nums2[index-1];
               if(swapped){
                   //swap the values
                   int temp = prev2;
                   prev2 = prev1;
                   prev1 = temp;
                }
               //no swap case
                if(nums1[index] > prev1 && nums2[index] > prev2){
                   ans = noswap;
                }
                //swap case
               if(nums1[index] > prev2 && nums2[index] > prev1){
                  ans = min(ans, 1+swap);
                }
               if(swapped){
                   currswap = ans;
               }
               else{
                   currnoswap = ans;
               }
            }
            swap = currswap;    //neche se upar ki taraf jare hain
            noswap = currnoswap;
        }
        return min(swap, noswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 at beginning
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //we have to check whether previous indexes are swapped or not
        bool swapped = 0;
        int n = nums1.size();
        return solveTabu(nums1, nums2);
    }
