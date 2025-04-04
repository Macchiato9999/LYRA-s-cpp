#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring> // ��Ӵ�ͷ�ļ���ʹ�� strlen ����
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
		scanf("%d", &x);//����x����˵�
		int l = 0, r = n - 1;//ȷ�����䷶Χ
		while (l < r) {
			int mid = l + r >> 1;//����1λ�൱�ڳ���2
			if (q[mid] >= x) r=mid;
			else l = mid+1;
		}
		if (q[l] == x) {
			printf("%d ", r);//�Ҷ˵�һ����[��˵�,n-1]֮��
			while (l < r)
			{
				int mid = l + r + 1 >> 1;//����1λ�൱�ڳ���2����Ϊд����l=mid������Ҫ��1
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