#include "header.h"

class Solution {
      public:
	int calcSum(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}

	int movingCount(int m, int n, int k) {
		int count = 0;
		queue<pair<int, int>> Q;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		vector<pair<int, int>> direction = {
		    {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
		Q.push(make_pair(0, 0));
		visited[0][0] = true;
		while (!Q.empty()) {
			auto point = Q.front();
			int x = point.first, y = point.second;
			Q.pop();
			if (calcSum(x) + calcSum(y) <= k) {
				count++;
			} else {
				continue;
			}
			for (auto &one : direction) {
				if (x + one.first >= 0 && x + one.first < m && y + one.second >= 0 && y + one.second < n) {
					if (!visited[x + one.first][y + one.second]) {
						Q.push(make_pair(x + one.first, y + one.second));
						visited[x + one.first][y + one.second] = true;
					}
				}
			}
		}
		return count;
	}
};