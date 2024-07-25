https://www.naukri.com/code360/problems/subsequences-of-string_985087

#include <bits/stdc++.h> 
#include <vector>
vector<string> solve(string &str, string &empty, int len, int index){
	vector<string> ans;
	//base case
	if(index == len){
		ans.push_back(str);
	}
	//pick wala case
	empty = empty + str[index];
	solve(str, empty, len, index+1);
	empty.pop_back();
	solve(str, empty, len, index+1);
	ans.push_back(empty);
	return ans;
}
vector<string> subsequences(string str){
	//bit manipulation
	// int n = str.length();
	// vector<string>ans;
	// for (int num = 0; num < (1 << n); num++) {
	// 	string sub = "";
	// 	for (int i = 0; i < n; i++) {
	// 		//check if the ith bit is set or not
	// 		if (num & (1 << i)) {
	// 			sub += str[i];
	// 		}
	// 	}
	//Don't include empty string
	// 	if (sub.length() > 0) {
	// 		ans.push_back(sub);
	// 	}
	// }
	// sort(ans.begin(), ans.end());
	// return ans;

	//using recursion
	string empty = "";
	return solve(str, empty, str.length(), 0);
}
