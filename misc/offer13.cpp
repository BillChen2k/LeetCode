#include <vector>

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

	int count = 0;
	int size_m = 0;
	int size_n = 0;

	void dfs(int x, int y, int k, vector<vector<bool>> &visited, vector<vector<bool>> &marked) {
		if (x < 0 || y < 0 || x >= size_m || y >= size_n) {
			return;
		}
		if (visited[x][y]) {
			return;
		}
		if (calcSum(x) + calcSum(y) > k) {
			return;
		}
		visited[x][y] = true;
		if (!marked[x][y]) {
			count++;
			marked[x][y] = true;
		}
		dfs(x + 1, y, k, visited, marked);
		dfs(x, y + 1, k, visited, marked);
		dfs(x - 1, y, k, visited, marked);
		dfs(x, y - 1, k, visited, marked);
		// visited[x][y] = false;
	}

	int movingCount(int m, int n, int k) {
		size_m = m;
		size_n = n;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		vector<vector<bool>> marked(m, vector<bool>(n, false));
		dfs(0, 0, k, visited, marked);
		return count;
	}
};