/*从 1∼n这 n
 个整数中随机选出 m
 个，输出所有可能的选择方案。

输入格式
两个整数 n,m
 ,在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面*/

#include<iostream>
using namespace std;
int n;
int m;
int place[25];
void dfs(int u, int start) {//u表示当前枚举到哪个位置,start表示当前最小可以从哪个数开始选
	if (u + n - start < m) return;//剪枝 如果把剩下的数都选上也不够m个数，则当前分支不可能有解
	if (u >m ) {
		for (int i = 1; i <= m; i++) {
			cout << place[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++) {
		
			place[u] = i;
			dfs(u + 1,i+1);
			place[u] = 0;//回溯
		
	}
}

int main() {
	cin >> n >> m;
	dfs(1,1);
	return 0;
}