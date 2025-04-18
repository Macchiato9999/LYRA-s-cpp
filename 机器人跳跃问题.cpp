﻿/*机器人正在玩一个古老的基于 DOS 的游戏。
游戏中有 N+1
 座建筑——从 0
 到 N
 编号，从左到右排列。

编号为 0
 的建筑高度为 0
 个单位，编号为 i
 的建筑高度为 H(i)
 个单位。

起初，机器人在编号为 0
 的建筑处。

每一步，它跳到下一个（右边）建筑。

假设机器人在第 k
 个建筑，且它现在的能量值是 E
，下一步它将跳到第 k+1
 个建筑。

如果 H(k+1)>E
，那么机器人就失去 H(k+1)−E
 的能量值，否则它将得到 E−H(k+1)
 的能量值。

游戏目标是到达第 N
 个建筑，在这个过程中能量值不能为负数个单位。

现在的问题是机器人至少以多少能量值开始游戏，才可以保证成功完成游戏？

输入格式
第一行输入整数 N
。

第二行是 N
 个空格分隔的整数，H(1),H(2),…,H(N)
 代表建筑物的高度。

输出格式
输出一个整数，表示所需的最少单位的初始能量值上取整后的结果。

数据范围
1≤N,H(i)≤105
,
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring> // 添加此头文件以使用 strlen 函数
#include<cstdio>
#include<vector>
#include<cstdio>
using namespace std;
const int N = 100010;
int n;
int h[N];
bool check(int e)
{
	for (int i = 1; i <=n; i++)
	{
		e = e * 2 - h[i];
		if (e >= 1e5)return true;

		if (e < 0)return false;
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 1; i <=n; i++)cin >> h[i];
	int l = 0, r = 1e5;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
		
	return 0;
}