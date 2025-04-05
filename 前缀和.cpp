#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int a[1000];
    int s[1000];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i]+s[i-1];
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}



