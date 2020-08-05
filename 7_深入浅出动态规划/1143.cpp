#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <limits.h>
#include <queue>

using namespace std;
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				if(text1[i] == text2[j]){
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return dp[m][n];
	}
};
//
// Created by Kevin on 2020/8/2 9:27.
// 求真求实，大气大为
//

