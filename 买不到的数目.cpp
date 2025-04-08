/*小明开了一家糖果店。

他别出心裁：把水果糖包成4颗一包和7颗一包的两种。

糖果不能拆包卖。

小朋友来买糖的时候，他就用这两种包装来组合。

当然有些糖果数目是无法组合出来的，比如要买 10 颗糖。

你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。

大于17的任何数字都可以用4和7组合出来。

本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。

输入格式
两个正整数 n, m
，表示每种包装中糖的颗数。

输出格式
一个正整数，表示最大不能买到的糖数。

数据范围
2≤n, m≤1000
，
保证数据一定有解。*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

bool dfs(int m, int p, int q) {
	if (!m)return true;
	if (m >= p && dfs(m - p, p, q))return true;
	if (m >= q && dfs(m - q, p, q))return true;
	return false;
}

using namespace std;
int main() {
	int m, p, q;
	cin>>p>>q;
	for (int i = 1; i <= 1000; i++) {
		if(!dfs(i,p,q))m =i;
	}
	cout << m << endl;
}



