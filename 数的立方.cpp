#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring> // 添加此头文件以使用 strlen 函数
#include<cstdio>

using namespace std;
int n, m;
int main() {
	double n;
	cin >> n;
	double l = -10000;
	double r = 10000;
	double mid;
	while (r-l>1e-8) {
		mid = (l + r) / 2;
		if (mid*mid*mid>=n) {
			r=mid;
		}
		else
			l=mid;
	}
	printf("%lf\n", l);
	return 0;
}