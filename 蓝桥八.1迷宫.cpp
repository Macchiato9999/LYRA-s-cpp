/*给定一个长度为 N
的数列，A1, A2, …AN
，如果其中一段连续的子序列 Ai, Ai + 1, …Aj
之和是 K
的倍数，我们就称这个区间[i, j]
	是 K
		倍区间。

		你能求出数列中总共有多少个 K
		倍区间吗？

		输入格式
		第一行包含两个整数 N
		和 K
		。

		以下 N
		行每行包含一个整数 Ai
		。

		输出格式
		输出一个整数，代表 K
		倍区间的数目。

		数据范围
		1≤N, K≤100000
		,
		1≤Ai≤100000

		输入样例：
		5 2
		1
		2
		3
		4
		5
		输出样例：
		6*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
char arr[10][10];
int ans=0;
bool visited[10][10];
void solve(int a, int b, char x)
{
	if (a < 0 || a > 9 || b < 0 || b > 9) {
		ans++;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				visited[i][j] = false;
			}
		}
	}
	else {
		if (visited[a][b]) {
			return;
		}
		visited[a][b] = true;
			if (x == 'U') { b--; }
			else if (x == 'D') { b++; }
			else if (x == 'L') { a--; }
			else if (x == 'R') { a++; }
			solve(a, b, arr[a][b]);
		
	}
	return;
}
using namespace std;
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			solve(j, i, arr[j][i]);
		}
	}
	cout << ans;
	return 0;
}



