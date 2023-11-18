#include <algorithm>

long long getTrappedWater(long long* arr, int n) {
    int* left = new int[n];
    int* right = new int[n];
    left[0] = arr[0];

    for(int i=1; i<n; i++) {
        left[i] = std::max(left[i-1], static_cast<int>(arr[i]));  // to ensure that the values stored in the left and right arrays are of type int
    }

    right[n-1] = static_cast<int>(arr[n-1]);
    for(int i=n-2; i>=0; i--) {
        right[i] = std::max(right[i+1], static_cast<int>(arr[i]));  // to ensure that the values stored in the left and right arrays are of type int
    }

    long long ans = 0; // Change the type to long long
    for(int i=0; i<n; i++) {
        ans += (std::min(left[i], right[i]) - arr[i]);
    }

    delete[] left; // Don't forget to release the memory
    delete[] right;

    return ans;
}
