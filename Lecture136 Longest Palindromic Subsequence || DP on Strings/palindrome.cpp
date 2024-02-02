int solveTabu(string text1, string text2){
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                  ans = 1 + next[j+1];
                }
                else{
                  ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string reverseStr = s;
        reverse(s.begin(), s.end());
        return solveTabu(s, reverseStr);
    }
