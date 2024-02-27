//BINARY SEARCH
#include <bits/stdc++.h>
using namespace std;

int BinSearch(int key, vector<int> &vec, int start, int end) {
	while (start <= end) {
		int mid = start + (end - start) / 2;  // to prevent integer overflow
		if (vec[mid] == key)
			return mid;
		else if (key < vec[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main() {
	int n, key;
	cout << "Enter num of elements: " << endl;
	cin >> n;
    cout << "Enter numbers in sorted manner: " << endl;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int inp;
        cin >> inp;
        vec.push_back(inp);
	}
    cout << "Enter element to be searched: " << endl;
	cin >> key;
	int ans = BinSearch(key, vec, 0, n - 1);
	cout << "Index: " << ans;
}
