#include<iostream>
#include<algorithm>
#include<cstring> // 添加此头文件以使用 strlen 函数
using namespace std;
const int N = 110;

int n;
char start[N], aim[N]; // 修改为非 const 以便输入

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