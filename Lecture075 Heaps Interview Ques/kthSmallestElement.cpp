class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> q;
        
        //push till k elements
        for(int i=0; i<k; i++){
            q.push(arr[i]);
        }
        
        //pop remaining smallest elements
        for(int i=k; i<=r; i++){
            if(arr[i] < q.top()){
               q.pop();
               q.push(arr[i]);
            }
        }
        int ans = q.top();
        return ans;
    }
};
