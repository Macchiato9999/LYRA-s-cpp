#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring> // 添加此头文件以使用 strlen 函数
#include<cstdio>

using namespace std;

const int N = 100010;
int n, m;
int q[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);//二分x的左端点
		int l = 0, r = n - 1;//确定区间范围
		while (l < r) {
			int mid = l + r >> 1;//右移1位相当于除以2
			if (q[mid] >= x) r=mid;
			else l = mid+1;
		}
		if (q[l] == x) {
			printf("%d ", r);//右端点一定在[左端点,n-1]之间
			while (l < r)
			{
				int mid = l + r + 1 >> 1;//右移1位相当于除以2;因为写的是l=mid，所以要加1
				if (q[mid] <= x) l = mid;
				else r = mid - 1;
			}
			cout << l<<endl;
		}
		else {
			printf("-1 -1\n");
		}
	}
	return 0;
}
