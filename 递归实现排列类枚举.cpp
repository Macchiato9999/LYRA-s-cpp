/*把 1?n
 这 n
 个整数排成一行后随机打乱顺序，输出所有可能的次序。

输入格式
一个整数 n
。

输出格式
按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。*/
#include<iostream>
using namespace std;
int n;
int st[10];//st[i]表示第i个数是否被使用过,0表示未使用，1表示使用过
int path[10];//每一个位置填的数

void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			cout << path[i] << ' ' ;
		}
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (st[i] == 0) {
		st[i] = 1;
		path[u] = i;
		dfs(u + 1);
		st[i] = 0;
	    }
	}
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}