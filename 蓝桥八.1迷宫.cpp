/*X星球的一处迷宫游乐场建在某个小山坡上。
它是由10x10相互连通的小房间组成的。

房间的地板上写着一个很大的字母。
我们假设玩家是面朝上坡的方向站立，则：
L表示走到左边的房间，
R表示走到右边的房间，
U表示走到上坡方向的房间，
D表示走到下坡方向的房间。

X星球的居民有点懒，不愿意费力思考。
他们更喜欢玩运气类的游戏。这个游戏也是如此！

开始的时候，直升机把100名玩家放入一个个小房间内。
玩家一定要按照地上的字母移动。

迷宫地图如下：
------------
UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR
------------

请你计算一下，最后，有多少玩家会走出迷宫?
而不是在里边兜圈子*/
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



