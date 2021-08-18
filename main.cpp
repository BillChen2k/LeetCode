#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> num;
    vector<int> costs;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
	    cin >> costs[i];
    }
}