/*�� 1?n
 �� n
 �������ų�һ�к��������˳��������п��ܵĴ���

�����ʽ
һ������ n
��

�����ʽ
���մ�С�����˳��������з�����ÿ�� 1
 ����

���ȣ�ͬһ��������������һ���ո������

��Σ�����������ͬ���У���Ӧ�±����һһ�Ƚϣ��ֵ����С������ǰ�档*/
#include<iostream>
using namespace std;
int n;
int st[10];//st[i]��ʾ��i�����Ƿ�ʹ�ù�,0��ʾδʹ�ã�1��ʾʹ�ù�
int path[10];//ÿһ��λ�������

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