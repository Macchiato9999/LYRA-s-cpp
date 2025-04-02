#include<iostream>
using namespace std;
/*int main() {
	int n;
	cin >> n;
	int f[64];
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	for (int i = 1; i <= n; i++) {
		cout << f[i] << " ";
	}
	return 0;

}*/
int main() {
	int n;
	cin >> n;

	int a = 0, b = 1;
	for(int i=0;i<=n;i++)
	{
		cout << a << " ";
		int c = a + b;
		a = b;
		b = c;
	}
	return 0;
}