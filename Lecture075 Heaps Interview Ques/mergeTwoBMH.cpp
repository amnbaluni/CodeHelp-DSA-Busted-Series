//0 base indexing ka logic hai
void heapify(vector<int>& arr, int n, int i){
      int largest = i;
      int left = 2*i + 1;
      int right = 2*i + 2;
      if(left <n && arr[largest] < arr[left]){
        largest = left;
      }
      if(right <n && arr[largest] < arr[right]){
        largest = right;
      }
      if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n,largest);
     }
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step1 merge two arrays into one
        vector<int> ans;
       
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        int size = ans.size();
        //step2 build Heap using that array
        for(int i=size/2 - 1; i>=0; i--){
            heapify(ans, size, i);
        }
        return ans;   
    }
