https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i){
        int largest = i;
        //0 based indexing
        int left = (2 * i) + 1; 
        int right = (2 * i) + 2;

        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;
        if(largest != i){
            swap(nums[largest], nums[i]);
            maxHeapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums, int n){
        for(int i = n/2-1; i >= 0; i--)
            maxHeapify(nums, n, i);
        for(int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // heapSort(nums, nums.size());
        // return nums;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int i = 0;
        while(!pq.empty()){
            int top = pq.top();
            nums[i] = top;
            pq.pop();
            i++;
        }
        return nums;
    }
};
