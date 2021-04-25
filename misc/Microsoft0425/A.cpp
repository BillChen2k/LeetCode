#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	int len = 0;
	for (int i = 0; i < A.size(); i++) {
        if (i == A.size() - 1) {
            if (A[i] == A[i - 1]) {
                len--;
                break;
            }
            else {
                len++;
                break;
            }
        }
		bool duplicate = false;
		while (i < A.size() - 1 && A[i] == A[i + 1]) {
			duplicate = true;
			i++;
		}
        len += duplicate ? 2 : 1;
	}
    return len;
}

int main() {
    vector<int> arr = {2,3,3,2,2,2,1};
    cout << solution(arr);
}