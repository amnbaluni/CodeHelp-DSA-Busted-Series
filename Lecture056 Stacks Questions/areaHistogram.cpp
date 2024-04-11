class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};

***************************************************************************8

class Solution {
public:
vector<int> prevElements(vector<int>& heights){
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for(int i=0; i<heights.size(); i++){
            int curr = heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextElements(vector<int>& heights){
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for(int i=heights.size()-1; i>=0; i--){
            int curr = heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevElements(heights);
        vector<int> next = nextElements(heights);
        int maxArea = INT_MIN;

        int n = heights.size();
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1) next[i] = n;
            int b = next[i]-prev[i]-1;
            int area = l*b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};    
