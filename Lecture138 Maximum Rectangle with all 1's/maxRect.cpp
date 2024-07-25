https://leetcode.com/problems/maximal-rectangle/description/

Refer question - Largest Area in Histogram  (Lecture 56)

TC = O(n*(m+n))
SC = O(m) or O(n)  
  
#include <stack>
#include <vector>
#include <limits.h>
vector<int> nextSmallerElement(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);

  for (int i = n - 1; i >= 0; i--) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }
    // ans is stack ka top
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
  stack<int> s;
  s.push(-1);
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr) {
      s.pop();
    }
    // ans is stack ka top
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

int largestRectangleArea(vector<int> &heights) {
  int n = heights.size();

  vector<int> next(n);
  next = nextSmallerElement(heights, n);

  vector<int> prev(n);
  prev = prevSmallerElement(heights, n);

  int area = INT_MIN;
  for (int i = 0; i < n; i++) {
    int l = heights[i];

    if (next[i] == -1) {
      next[i] = n;
    }
    int b = next[i] - prev[i] - 1;
    int newArea = l * b;
    area = max(area, newArea);
  }
  return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
	//n rows
	//m columns
	int maxi = INT_MIN;
	vector<int> histogram(m, 0);
	for(int i=0; i<n; i++){
		//to create histogram array
		for(int j=0; j<m; j++){
			if(mat[i][j] == '1'){
				histogram[j]++;
			}
			else{
                histogram[j] = '0';
			}
		}
		maxi = max(maxi, largestRectangleArea(histogram));
	}
	return maxi;
}
