#include<iostream>
#include<algorithm>
#include<cstring> // ��Ӵ�ͷ�ļ���ʹ�� strlen ����
using namespace std;
const int N = 110;

int n;
char start[N], aim[N]; // �޸�Ϊ�� const �Ա�����

void turn(int i)
{
	if (start[i] == '*') start[i] = 'o';
	else start[i] = '*';
}
int main()
{
	cin >> start >> aim;
	n = strlen(start);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (start[i] != aim[i])
		{
			turn(i), turn(i + 1);
			res++;
			
		}
	}
	cout << res << endl;
}