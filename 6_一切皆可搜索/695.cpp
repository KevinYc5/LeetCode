#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
class Solution {
public:
	vector<int> direction{-1, 0, 1, 0, -1};

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = m? grid[0].size(): 0, local_area, area = 0, x, y;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j]) {
					local_area = 1;
					grid[i][j] = 0;
					stack<pair<int, int>> island;
					island.push({i, j});
					while (!island.empty()) {
						auto [r, c] = island.top();
						island.pop();
						for (int k = 0; k < 4; ++k) {
							x = r + direction[k], y = c + direction[k+1];
							if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
								grid[x][y] = 0;
								++local_area;
								island.push({x, y});
							}
						}
					}
					area = max(area, local_area);
				}
			}
		} return area;
	}
};
//
// Created by Kevin on 2020/7/24 15:35.
// 求真求实，大气大为
//
