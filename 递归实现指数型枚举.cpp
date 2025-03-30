/*
从 1∼n这 n个整数中随机选取任意多个，输出所有可能的选择方案。

输入格式
输入一个整数 n
。

输出格式
每行输出一种方案。

同一行内的数必须升序排列，相邻两个数用恰好 1
个空格隔开。

对于没有选任何数的方案，输出空行。

本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。*/

#include<iostream>
#include<cstring>
using namespace std;
const int N = 15;
int n;
int st[N];//st[i]表示第i+1个数的状态，0表示未选，1表示选了，2表示不选
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++)
		{
			if (st[i] == 1)
				cout << i + 1 << ' ';
		}
		cout << endl;
		return;
	}
	st[u] = 2;
	dfs(u + 1);//第一个分支：不选
	st[u] = 0;//回复现场

	st[u] = 1;
	dfs(u + 1);//第二个分支：选
	st[u] = 0;//回复现场
}
int main() {
	cin >> n;
	dfs(0);

	return 0;
}