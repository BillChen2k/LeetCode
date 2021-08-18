#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int len;
		cin >> len;
		int ans = -1;
		vector<int> arr(len);
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		if (arr.size() == 1) {
			ans = arr[0];
		} else {
			sort(arr.begin(), arr.end());
			int last = arr[0];
			for (int i = 1; i < arr.size(); i++) {
				if (i < arr.size() - 1 && arr[i] != last && arr[i] != arr[i + 1] ||
				    i == arr.size() - 1 && arr[i] != last) {
					ans = arr[i];
					break;
				}
				last = arr[i];
			}
		}

		cout << ans << endl;
	}
	return 0;
}