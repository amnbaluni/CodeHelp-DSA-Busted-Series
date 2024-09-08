https://www.naukri.com/code360/problems/triplets-with-given-sum_893028

#include <bits/stdc++.h> 
#include <set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
 vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < K) {
                j++;
            }
            else if (sum > K) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

 ---------------------------------------------------------
https://leetcode.com/problems/3sum
 
 vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target) {
                    s.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
 
