#include <bits/stdc++.h> 
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    //0 based indexing
    int left = 2*i+1;
    int right = 2*i+2;
    if(left <n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n,largest);
    }
}

vector<int> buildMaxHeap(vector<int> &arr)
{   int n = arr.size();
    for(int i = n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }
    return arr;
}
