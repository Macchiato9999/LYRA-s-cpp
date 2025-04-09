/*
生日蜡烛

某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了236根蜡烛。

请问，他从多少岁开始过生日party的？

请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。



*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int ans = 0;
	int j;
	for (int i = 1; i <= 99; i++) {
		j = i;
		while (ans < 236) {
			ans += j;
			j++;
		}
		if (ans == 236) {
			cout << i;
			break;
		}
		ans = 0;
	}
	return 0;
}
