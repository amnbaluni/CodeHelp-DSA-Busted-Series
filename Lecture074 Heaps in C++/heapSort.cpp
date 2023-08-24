#include <bits/stdc++.h> 
void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> heapSort(vector<int>& arr, int n) {
	int size = n;
    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
		heapify(arr,size,1);
    }
	arr;
}
