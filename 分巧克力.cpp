#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
const int N = 100010;

using namespace std;
int n, k;
int h[N], w[N];
bool check(int mid) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (h[i] / mid) * (w[i] / mid);
		if (res >= k) return true;
	}
	return false;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		cin >> w[i];
	}
	int l = 1, r = 1e5;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
	return 0;
}



